we have no bread

#include "node.h"
#include "list.h"

//STRUCT WITH STRUCT INSIDE
libby struct{
    song_node* library[27];
    int size[27];
}


int conSym(char c){
    int i = conLet(c);
    if (i < 65 || i > 90){
        return 91;
    }
    return i;
}

struct song_node ** init(){
  struct libby l = calloc(1,sizeof(struct libby));
  return l;
}

void add(struct libby l, char* artist, char* title){
  int i = conSym(artist*)-'A’;
  insertArt(l->library[i], artist, title);
  l->size[i];++;
}

struct song_node * search_song(struct song_node ** library, char* artist, char* title ){
  return find(library[conSym(artist*)-'A'], artist, title];
}

struct song_node * search_artist(struct song_node ** library, char* artist ){
   return lost(library[conSym(artist*)-'A'], artist];
}

void print_letter(struct song_node ** library, char letter){
   print(library[conSym(letter)-'A']);
}

void print_artist(struct song_node ** library, char* artist){
   printArtist(library[conSym(artist*)-'A'], artist);
}

void print_library(struct song_node ** library) {
   for(int i = 0; i<27; i++){
         print(library[i]);
   }
}

void shuffle (struct libby l, int n) {
   int s = 0;
   int i = 0;
   while (i != 27){
       s+= l->size[i];
   }
   int s = rand() % s;
   int j = 0; 
   i = 0;
   while (s > j){
       j+=size[i];
       i++;
   }
   printf(“%s”, l->library[s-j]);
}

int delete_song(struct libby l, char* artist, char* title ) {
   int i = conSym(artist*)-'A’;
   return remov(l->library[i],artist,title);
   l->size[i]—;
}

void reset(struct song_node ** library) {
for(int i = 0; i<27; i++){
         free_list(library[i]);
   }   
}



















#include "node.h"
struct list{
  struct song_node *list;
  int size;
};


int conLet(char c){
  if ((int) c > 96 && (int) c < 123 ){
    return c - 32;
  }
  return (int) c;
}



int strcmpi( char *s1, char *s2 ){
  int over;
  int under;
  int i = 0;
  while(s1[i] != '\0' && s2[i] != '\0'){
    over = conLet(s1[i]);
    under = conLet(s2[i]); //treat UPPERCASE as lowercase
    if(over - under != 0){
      return under - over; //if over positive, is alphabetically firster
    }
    i++;
  }
  return (int) s2[i] - (int) s1[i];  //if over null, then under positive indicating over is alphabetically firster
}



struct song_node* makeSong(char*a, char*t){
  struct song_node* s = (struct song_node*) malloc(sizeof(struct song_node));
  strncpy(s->artist, a, sizeof(s->artist)-1);
  strncpy(s->title, t, sizeof(s->title)-1);
  return s;
}
struct song_node* insertFront(struct song_node* list, char* a, char* t){
  struct song_node* s = makeSong(a, t);
  s->next = list;
  return s;
}



struct song_node* insertArt(struct song_node* list, char* a, char* t){
  struct song_node* s = makeSong(a, t);
  if(strcmpi(s->artist, list->artist) >= 0 && strcmpi(s->title, list->title) >= 0){   //SUPERFIRST
    s->next = list;
    return s;
  }                                          //if s must add to right
  struct song_node* i = list;   //starting at first node:
  while(i->next != NULL){
    int firstinessArt = strcmpi(s->artist, i->next->artist);
    int firstinessTit = strcmpi(s->title, i->next->title) >= 0;
    if (firstinessArt > 0){
       s->next = i->next;
       i->next = s;
       return list;
    }
    if (firstinessArt == 0 && firstinessTit >= 0){
                           //comparison if artist gives no info
      s->next = i->next;
      i->next = s;
      return list;       //samish
    }
    i = i->next;   //increment current
  }
  //if s is SUPERLAST, i = last node
  i->next = s;   //explanatory, probably not needed but looks better

  return list;
}



void print(struct song_node* list){
  printf("%s: ", list->artist);
  for(struct song_node* i = list; i != NULL; i=i->next){
    printf("[%s] ", i->title);
  }
  printf("\n");
}



struct song_node* find(struct song_node* list, char*a, char*t){
  struct song_node* i = list;
  while (i != NULL){
    if (!strcmpi(a, i->artist) && !strcmpi(t, i->title)){
       return i;
    }
    i = i-> next;
  }
  return i;   //null
}



struct song_node* lost(struct song_node* list, char*a){
   struct song_node* i = list;
   while (i != NULL){
    if (!strcmpi(a, i->artist)){
       return i;
    }
    i = i-> next;
   }
  return i;
}



int size(struct song_node* list){
  int s = 0;
  struct song_node* i = list;
  while(i != NULL){
    i = i->next;
    s++;
  }
  return s;
}



struct song_node* rando(struct song_node* list){
  //need to determine size first
  int r = rand() % size(list)-1;
  struct song_node* i = list;
  while(r != 0){
    i = i->next;
    r--;
  }
  return i;
}



struct song_node* remov(struct song_node* list, char*a, char*t){

  struct song_node* i = list;
  if (!strcmpi(i->artist, a) && !strcmpi(i->title, t)){
    list = list->next;     // if start node is removable just push ‘list’ right
  }
  while(i->next != NULL){ //will evaluate all except last node
    if (!strcmpi(i->next->artist, a) && !strcmpi(i->next->title, t)){    //otherwise, need 2 nodes as reference: one before removable, one after
      struct song_node* temp = i->next;
      i->next = i->next->next; //can be null but not exceed            //before sets next to after, jumping over
      return temp;    //OR free(temp);   and returntype void                                             //technically, null is also a node that before can jump to
    }   //dont need to eval last note; we compare by ->next!!!
  }

  return NULL;
}



struct song_node * free_list(struct song_node * list){
  struct song_node* orig;
  while(list != NULL){
    orig = list->next;
    free(list);
    list = orig;
  }
  return NULL;
}



void printArtist(struct song_node * list, char*a){
     struct song_node* i = list;
     while (i != NULL){
        if (!strcmpi(i->artist, a)){
            printf("%s : %s ", a, i->title);
            i = i->next;
            while(i != NULL && !strcmpi(i->artist, a)){
                printf("%s", i->title);
            }
           return;
        }
        i = i->next;
     }
     printf("cringe");
   }

