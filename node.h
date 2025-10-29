#ifndef NODE_H

#define NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
  char artist[100];
  char title[100];
  struct song_node *next;
};

#endif
