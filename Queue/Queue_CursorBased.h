// Cursor-Based Implementation of Queue
#define MAX 10
#include <stdio.h>

typedef struct node {
	char data;
	int next;
} Node;

typedef struct {
	Node nodes[MAX];
	int avail;
} VirtualHeap;

VirtualHeap VH; // only accessible within this header file

typedef enum {
	FALSE,
	TRUE
} boolean;

typedef int Nodes;

typedef struct {
	Nodes front;
	Nodes rear;
} Queue;

void initQueue(Queue *Q);
void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
boolean isEmpty(Queue Q);
void enqueue(Queue *Q, char data);
void dequeue(Queue *Q);
char peek(Queue Q);
void display(Queue *Q);

void initVirtualHeap(VirtualHeap *VH) {
	int i, n = MAX-1;
	for (i = n; i >= 0; i--) {
		VH->nodes[i].next = i-1;
	}
	VH->avail = n;
}

void initQueue(Queue *Q) {
	initVirtualHeap(&VH);
	Q->front = -1;
	Q->rear = -1;
}

int allocSpace(VirtualHeap *VH) {
	int avail = VH->avail;
	if (VH->avail != -1) {
		VH->avail = VH->nodes[avail].next;
	}
	return avail;
}

void deallocSpace(VirtualHeap *VH, int index) {
	if (index >= 0 && index < MAX) {
		VH->nodes[index].next = VH->avail;
		VH->avail = index;
	}
}

boolean isEmpty(Queue Q) {
	return Q.front == -1 ? TRUE : FALSE;
}

void enqueue(Queue *Q, char data) {
	Nodes temp = allocSpace(&VH);
	if (temp != -1) {
		VH.nodes[temp].data = data;
		VH.nodes[temp].next = -1;
		if (Q->rear != -1) {
			VH.nodes[Q->rear].next = temp;
			Q->rear = temp;
		} else {
			Q->front = temp;
			Q->rear = temp;
		}
	}
}

void dequeue(Queue *Q) {
	if (!isEmpty(*Q)) {
		Nodes temp = Q->front;
		if (Q->front == Q->rear) {
			Q->front = Q->rear = -1;
		} else {
			Q->front = VH.nodes[temp].next;
		}
		deallocSpace(&VH, temp);
	}
}

char peek(Queue Q) {
	if (Q.front != -1) {
		return VH.nodes[Q.front].data;
	}
}

// This display function assumes there's no duplicate elements
void display(Queue *Q) {
	if (Q->front != -1) {
		char data = VH.nodes[Q->front].data; // will have to compare every member for structures
	
		do {
			printf("%c ", peek(*Q));
			enqueue(Q, peek(*Q));
			dequeue(Q);
		} while (data != peek(*Q));
	}
}
