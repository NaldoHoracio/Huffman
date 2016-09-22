#pragma once
#include "priorityQueue.h"


Node* create_empty_tree();

void printPreOrder(Node *bt);
/* Converte a lista em árvore chamando sucessivos merges */
Node *buildTree(Node *list);
/* Merge de 2 nodes da fila 
   Adicionando pai '*', e devolvendo para a fila */
Node *merge(Node* queue);
