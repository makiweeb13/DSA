// Cursor-Based Implementation of Stack

#define MAX 20
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

typedef int Stack;

void initStack(Stack *A);
void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index); 
void push(Stack *A, char data); 
void display(Stack A);
void pop(Stack *A);
boolean isEmpty(Stack A);

void initVirtualHeap(VirtualHeap *VH) {
	int i, n = MAX-1;
	for (i = n; i >= 0; i--) {
		VH->nodes[i].next = i-1;
	}
	VH->avail = n;
}

void initStack(Stack *A) {
	initVirtualHeap(&VH);
	*A = -1;
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

boolean isEmpty(Stack A) {
	return A == -1 ? TRUE : FALSE;
}

void push(Stack *A, char data) {
	Stack temp = allocSpace(&VH);
	if (temp != -1) {
		VH.nodes[temp].data = data;
		VH.nodes[temp].next = *A;
		*A = temp;
	}
}

void pop(Stack *A) {
	if (isEmpty(*A) == FALSE) {
		Stack temp = *A;
		*A = VH.nodes[temp].next;
		deallocSpace(&VH, temp);
	}
}

void display(Stack A) {
	Stack *ptr, temp = -1;
	ptr = &A;
	while (*ptr != -1) {
		push(&temp, VH.nodes[*ptr].data);
		pop(ptr);
	}
	ptr = &temp;
	while (*ptr != -1) {
		printf("%c", VH.nodes[*ptr].data);
		push(&A, VH.nodes[*ptr].data);
		pop(ptr);
	}
}
