#include "priorityQueue.h"

Node* createPriorityQueue(){
    return NULL;
}

int isEmpty(Node *node){
	return ((node == NULL) ? 1 : 0);
}
void printPriorityQueue(Node *node){
	Node *p_aux;
	if(node == NULL)
		printf("\nEmpty Priority Queue.\n");
	for(p_aux = node; p_aux != NULL; p_aux = p_aux->Next){
		printf("Character: %c -- Frequency: %d  ---> ", p_aux->n_character, p_aux->n_frequency);
	}
}

Node* insert(Node *node, unsigned char character, int frequency){
	if((node == NULL) || (frequency <= node->n_frequency)){
		Node *newNode = (Node*) malloc(sizeof(Node));
		newNode->n_character = character;
		newNode->n_frequency = frequency;
		newNode->p_left = NULL;
		newNode->p_right = NULL;
		newNode->Next = node;
		printf("\nInsert: %c -- Frequency: %d\n", character, frequency);
		return newNode;
	}
	else{
		Node *p_aux = node;
		Node *newNode = (Node*) malloc(sizeof(Node));
		while(p_aux->Next != NULL && frequency > p_aux->Next->n_frequency){
		        p_aux = p_aux->Next;
		}
		newNode->Next = p_aux->Next;
		newNode->n_character = character;
		newNode->n_frequency = frequency;
		newNode->p_left = NULL;
		newNode->p_right = NULL;
		p_aux->Next = newNode;
		printf("\nInsert: %c -- Frequency: %d\n", character, frequency);
		return node;
	}
}

Node *insertTreeNode(Node *node, Node *queueNode){
	if(node == queueNode){
		queueNode->Next = NULL;
		return queueNode;
	}
	else if((node == NULL) || (queueNode->n_frequency <= node->n_frequency)){
			queueNode->Next = node;
			return queueNode;
		}
	else{
		Node *p_aux = node;
		while(p_aux->Next != NULL && queueNode->n_frequency > p_aux->Next->n_frequency){
		        p_aux = p_aux->Next;
		}
		queueNode->Next = p_aux->Next;
		p_aux->Next = queueNode;
		return node;
	}
}



