#pragma once
#include "FrenquencyCounter.h"

typedef struct node Node;
struct node{
  unsigned char n_character;
  int n_frequency; 
  Node *Next;
  Node *p_left;
  Node *p_right;
};

Node* createPriorityQueue();

int isEmpty(Node *node);

void printPriorityQueue(Node *node);

/* Insere no começo da piorityQueue */
Node* insert(Node *node, unsigned char character, int frequency);

/* Insere o nó com merge na PiorityQueue */
Node *insertTreeNode(Node *queue, Node *queueNode);



