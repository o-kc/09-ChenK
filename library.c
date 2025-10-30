#include "node.h"
#include "list.h"

int conSym(char c){
    int i = conLet(c);
    if (i < 65 || i > 90){
        return 91;
    }
    return i;
}

struct song_node ** init(){
  struct song_node** l = calloc(27,sizeof(struct song_node*));
  return l;
}

void add(struct song_node ** library, char* artist, char* title){
  int i = conSym(*artist)-'A';
  library[i] = insertArt(library[i], artist, title);

}

struct song_node * search_song(struct song_node ** library, char* artist, char* title ){
  return find(library[conSym(*artist)-'A'], artist, title);
}

struct song_node * search_artist(struct song_node ** library, char* artist ){
   return lost(library[conSym(*artist)-'A'], artist);
}

void print_letter(struct song_node ** library, char letter){
   print(library[conSym(letter)-'A']);
}

void print_artist(struct song_node ** library, char* artist){
   printArtist(library[conSym(*artist)-'A'], artist);
}

void print_library(struct song_node ** library) {
   for(int i = 0; i<27; i++){
         print(library[i]);
   }
}

void shuffle (struct song_node ** library, int n) {
  int s = 0;
  for(int i = 0; i<27; i++){
    s += size(library[i]);  //determine size
  }
  int pool[n];
  for(int i = 0; i<n; i++){
    pool[i] = rand() % s;  //determine songs to extract
  }                            //will need to create helper method in list
  int ref = 0;   //to determine order and pick song from that order
  for(int i = 0; i<27; i++){
    ref = shuffleHelp(library[i], ref, pool, n);
  }
}

int delete_song(struct song_node ** library, char* artist, char* title ) {
   int i = conSym(*artist)-'A';
   struct song_node * temp = library[i];
   library[i] = remov(library[i],artist,title);
   if (temp != library[i]){
     return 1;
   }
   return 0;
}

void reset(struct song_node ** library) {
for(int i = 0; i<27; i++){
         free_list(library[i]);
   }
}
