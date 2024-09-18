// Linkedlist Implementation of Stack

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *next;
} *Stack;

typedef enum {
	FALSE,
	TRUE
} boolean;

void initStack(Stack *A); 
void push(Stack *A, char data); 
void display(Stack A);
void pop(Stack *A);
boolean isEmpty(Stack A);

void initStack(Stack *A) {
	*A = NULL;
}

boolean isEmpty(Stack A) {
	return A == NULL ? TRUE : FALSE;
}

void push(Stack *A, char data) {
	Stack temp = (Stack) malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = data;
		temp->next = *A;
		*A = temp;
	}
}

void pop(Stack *A) {
	if (isEmpty(*A) == FALSE) {
		Stack temp = *A;
		*A = temp->next;
		free(temp);
	}
}

void display(Stack A) {
	Stack *ptr, temp = NULL;
	ptr = &A;
	while (*ptr != NULL) {
		push(&temp, (*ptr)->data);
		pop(ptr);
	}
	ptr = &temp;
	while (*ptr != NULL) {
		printf("%c", (*ptr)->data);
		push(&A, (*ptr)->data);
		pop(ptr);
	}
}
