// Array Implementation of Stack

#define MAX 10
#include <stdio.h>

typedef struct {
	char elem[MAX];
	int top;
} Stack;

typedef enum {
	FALSE,
	TRUE
} boolean;

void initStack(Stack *A); 
void push(Stack *A, char data); 
void display(Stack A);
void pop(Stack *A);
boolean isFull(Stack A);
boolean isEmpty(Stack A);


void initStack(Stack *A) {
	A->top = -1;
}

boolean isFull(Stack A) {
	return A.top == MAX-1 ? TRUE : FALSE;
}

boolean isEmpty(Stack A) {
	return A.top == -1 ? TRUE : FALSE;
}

void pop(Stack *A) {
	if (isEmpty(*A) == FALSE) {
		A->top--;
	}
}

void push(Stack *A, char data) {
	if (isFull(*A) == FALSE) {
		A->top++;
		A->elem[A->top] = data;
	}
}

void display(Stack A) {
	Stack temp;
	while (!isEmpty(A)) {
		push(&temp, A.elem[A.top]);
		pop(&A);
	}
	while (!isEmpty(temp)) {
		printf("%c", temp.elem[temp.top]);
		pop(&temp);
	}
}
