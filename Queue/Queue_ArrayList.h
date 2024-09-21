// Array Implementation of Queue

#include <stdio.h>
#define MAX 10

typedef struct {
	char elem[MAX];
	int front;
	int rear;
} Queue;

typedef enum {
	FALSE,
	TRUE
} boolean;

void initQueue(Queue *Q);
boolean isEmpty(Queue Q);
boolean isFull(Queue Q);
void enqueue(Queue *Q, char data);
void dequeue(Queue *Q);
char peek(Queue Q);
void display(Queue *Q);

void initQueue(Queue *Q) {
	Q->front = -1;
	Q->rear = -1;
}

boolean isEmpty(Queue Q) {
	return Q.front == -1 && Q.rear == -1 ? TRUE : FALSE;
}

boolean isFull(Queue Q) {
	return (Q.rear + 1) % MAX == Q.front ? TRUE : FALSE;
}

void enqueue(Queue *Q, char data) {
	if (!isFull(*Q)) {
		if (isEmpty(*Q)) {
			Q->front = Q->rear = 0;
		} else {
			Q->rear = (Q->rear + 1) % MAX;
		}
		Q->elem[Q->rear] = data;
	}
}

void dequeue(Queue *Q) {
	if (!isEmpty(*Q)) {
		if (Q->front == Q->rear) {
			Q->front = Q->rear = -1;
		} else {
			Q->front = (Q->front + 1) % MAX;
		}
	}
}

char peek(Queue Q) {
	if (Q.front != -1) {
		return Q.elem[Q.front];
	}
}

void display(Queue *Q) {
	int end = (Q->rear + 1) % MAX;
	while (Q->front < end) {
		printf("%c ", peek(*Q));
		enqueue(Q, peek(*Q));
		dequeue(Q);
	}
}
