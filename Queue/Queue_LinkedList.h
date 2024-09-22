// Linked List Implementation of Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *next;
} *Node;

typedef struct {
	Node front;
	Node rear;
} Queue;

typedef enum {
	FALSE,
	TRUE
} boolean;

void initQueue(Queue *Q);
boolean isEmpty(Queue Q);
void enqueue(Queue *Q, char data);
void dequeue(Queue *Q);
char peek(Queue Q);
void display(Queue *Q);

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

boolean isEmpty(Queue Q) {
	return Q.front == NULL && Q.rear == NULL ? TRUE : FALSE;
}

void enqueue(Queue *Q, char data) {
	Node temp = (Node) malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = data;
		temp->next = NULL;
		if (Q->rear != NULL) {
			Q->rear->next = temp;
			Q->rear = temp;
		} else {
			Q->front = temp;
			Q->rear = temp;
		}
	}
}

void dequeue(Queue *Q) {
	if (!isEmpty(*Q)) {
		Node temp = Q->front;
		if (Q->front == Q->rear) {
			Q->front = Q->rear = NULL;
		} else {
			Q->front = temp->next;
		}
		free(temp);
	}
}

char peek(Queue Q) {
	if (Q.front != NULL) {
		return Q.front->data;
	}
}

// This display function assumes there's no duplicate elements
void display(Queue *Q) {
	if (Q->front != NULL) {
		char data = Q->front->data; // will have to compare every member for structures
	
		do {
			printf("%c ", peek(*Q));
			enqueue(Q, peek(*Q));
			dequeue(Q);
		} while (data != peek(*Q));
	}
}
