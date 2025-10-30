
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
  strncpy(s->artist, a, sizeof(s->artist)-1);    //WONT ADD NULL IF OVER 99, even if you raise capacity (length) of string
  s->artist[sizeof(s->artist)-1] = '\0';
  strncpy(s->title, t, sizeof(s->title)-1);
  s->title[sizeof(s->title)-1] = '\0';           //At that point, null index 99 as safeguard
  return s;
}



struct song_node* insertFront(struct song_node* list, char* a, char* t){
  struct song_node* s = makeSong(a, t);
  s->next = list;
  return s;
}



struct song_node* insertArt(struct song_node* list, char* a, char* t){
  struct song_node* s = makeSong(a, t);
  if (list == NULL) {                         //EMPTY LIST
     s->next = NULL;
     return s;
  }
  int firfirA = strcmpi(s->artist, list->artist);
  int firfirT = strcmpi(s->title, list->title);
  if(firfirA >= 0 || (firfirA == 0 && firfirT >= 0)){   //SUPERFIRST, but only check titles if OR equal
    s->next = list;
    return s;
  }                                          //if s must add to right
  struct song_node* i = list;   //starting at first node:
  while(i->next != NULL){
    int firstinessArt = strcmpi(s->artist, i->next->artist);
    int firstinessTit = strcmpi(s->title, i->next->title);
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
  if (list == NULL){
    return;
  }
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
  if (list == NULL){
    return NULL;
  }
  //need to determine size first
  int r = rand() % size(list);
  struct song_node* i = list;
  while(r != 0){
    i = i->next;
    r--;
  }
  return i;
}



struct song_node* remov(struct song_node* list, char*a, char*t){
  struct song_node* i = list;
  if (i == NULL){
    return NULL;
  }
  if (!strcmpi(i->artist, a) && !strcmpi(i->title, t)){
    struct song_node* temp = list->next;     // if start node is removable just push ‘list’ right
    free(list);
    return temp;
  }
  while(i->next != NULL){ //will evaluate all except last node
    if (!strcmpi(i->next->artist, a) && !strcmpi(i->next->title, t)){    //otherwise, need 2 nodes as reference: one before removable, one after
      struct song_node* temp = i->next;
      i->next = i->next->next; //can be null but not exceed            //before sets next to after, jumping over
      free(temp);
      return list;    //OR free(temp);   and returntype void           //technically, null is also a node that before can jump to
    }   //dont need to eval last note; we compare by ->next!!!
  }
  return list;
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
                i = i->next;
            }
           return;
        }
        i = i->next;
     }
     printf("artist not found");
   }

  int shuffleHelp(struct song_node * list, int ref, int* pool, int n){
    struct song_node* i = list;
    while (i != NULL){
      for(int j = 0; j < n; j++){
        if (ref == pool[j]){
          printf("[%s %s]  ", i->artist, i->title);
          break;
        }
      }
      ref++;
      i = i->next;
    }
    return ref;
  }
