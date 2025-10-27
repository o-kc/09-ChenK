#ifndef NODE_H

#define NODE_H
struct song_node{
  char artist[100];
  char title[100];
  struct song_node *next;
};

#endif
