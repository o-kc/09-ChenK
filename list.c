#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
int conLet(char c){
  if ((int) c > 64 && (int) c < 91 ){
    return c + 32;
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

struct song_node* insertAlpha(struct song_node* list, char* a, char* t){
  //asume I did this already I am sick and tired of forgetting that im using a linked list
}

struct song_node* find(struct song_node* list, char*a, char*t){
  //left to China
}

struct song_node* lose(struct song_node* list, char*a){
  //barebones. thats the secrete
}

int size(struct song_node* list){
  int i = 0;
  struct song_node j = list;
  while(list != NULL){
    j=j->next;
    i++;
  }
  return i;
}
struct song_node* random(struct song_node* list){
  //need to determine size first
  int r = (rand() * size(list))-1;
  struct song_node i = list;
  while(r != 0){
    i = i->next;
    r--;
  }
  return i;
}

struct song_node* remove(struct song_node* list, char*a, char*t){
  struct song_node* i = list;
  while(i->next != NULL){
    if (!strcmpi(i->next->artist, a) && !strcmpi(i->next->title, t)){
      struct song_node* temp = i->next;
      i->next = i->next->next; //can be null but not exceed
      return temp;
    }
  }
  return NULL;
}

struct node * free_list(struct node * list){
  struct node* orig;
  while(i != NULL){
    orig = list->next;
    free(list);
    list = orig;
  }
  return NULL;
}
