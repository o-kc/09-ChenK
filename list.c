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
  struct song_node* s = makeSong(a, t);
  if(strcmpi(s->title, list->title) >= 0){  //if s is firstest
    s->next = list;
    return s;
  }                             //if s must add to right
  struct song_node* i = list;   //start at first node:
  while(i->next != NULL){
    if (strcmpi(s->title, i->next->title) >= 0){  //s must be firster than current-next (item 2 if i = list)
      s->next = i->next; //s has current-next as next
      i->next = s; //current has s as next
      return s;    //you have ruined this loop
    }
    i = i->next;   //increment current
  }
  //if s is lastest, i = last node
  i->next = s;   //explanatory

  return s;
}
