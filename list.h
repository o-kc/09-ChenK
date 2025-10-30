
#ifndef LIST_H

#define LIST_H
int conLet(char c);

int strcmpi( char *s1, char *s2 );

struct song_node* makeSong(char*a, char*t);

struct song_node* insertArt(struct song_node* list, char* a, char* t);

void print(struct song_node* list);

struct song_node* find(struct song_node* list, char*a, char*t);

struct song_node* lost(struct song_node* list, char*a);

int size(struct song_node* list);

struct song_node* rando(struct song_node* list);

struct song_node* remov(struct song_node* list, char*a, char*t);

struct song_node * free_list(struct song_node * list);

void printArtist(struct song_node * list, char*a);

int shuffleHelp(struct song_node * list, int ref, int* pool, int n);
#endif
