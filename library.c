#include "node.h"
#include "list.h"
struct song_node ** init(){
  struct song_node** l = calloc(27,sizeof(struct song_node*));
  return l;
}

void add(struct song_node ** library, char* artist, char* title){
  insertArt(library[65-'A'], artist, title);
}

struct song_node * search_song(struct song_node ** library, char* artist, char* title ){

}
