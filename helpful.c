#include "helpful.h"


Node* create_empty_tree() {
	return NULL;
}

void printPreOrder(Node *bt){
	if(!isEmpty(bt)){
		printf("Character: %c -- Frequency: %d\n", bt->n_character, bt->n_frequency);
		printPreOrder(bt->p_left);
		printPreOrder(bt->p_right);
	}
}

Node *buildTree(Node *list){
	/* merge enquanto lista possuir elemento */
	while(list->Next != NULL){
			list = merge(list);
			printf("\nEstado atual da lista:\n");
			printPriorityQueue(list);
		}
	return list;
}

Node *merge(Node* queue){
	/* estabelecendo definições para o novo nó criado */
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->p_left = queue;
	newNode->p_right = queue->Next;

	/* após retirada dos 2 primeiros elementos, queue aponta para o terceiro */
	if(newNode->p_right->Next != NULL)
		queue = newNode->p_right->Next;
	else
		queue = newNode;

	newNode->p_left->Next = NULL;
	newNode->p_right->Next = NULL;
	newNode->n_character = '*';
	/* nó pai recebe a soma da frequencia dos filhos */
	newNode->n_frequency = newNode->p_left->n_frequency + newNode->p_right->n_frequency;

	/*inserindo novamente na fila, já */
	queue = insertTreeNode(queue, newNode);

	return queue;
}
