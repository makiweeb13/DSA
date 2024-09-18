#include <stdio.h>
//#include "Stack_ArrayList.h"
//#include "Stack_LinkedList.h"
#include "Stack_CursorBased.h"

int main() {
	Stack A;
	
	initStack(&A);
	
	push(&A, 'E');
	push(&A, 'v');
	push(&A, 'e');
	push(&A, 'r');
	push(&A, 'd');
	push(&A, 'a');
	push(&A, 'y');
	
	pop(&A);
	pop(&A);
	pop(&A);
	
	push(&A, 'y');
	push(&A, 'd');
	push(&A, 'a');
	push(&A, 'y');
	
	display(A);
	
	printf(" Means ");
	
	display(A); // original stack didn't change
	
	return 0;
}
