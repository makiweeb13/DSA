#include <stdio.h>
//#include "Queue_LinkedList.h"
//#include "Queue_CursorBased.h"
#include "Queue_ArrayList.h"

int main() {
	
	Queue Q;
	
	initQueue(&Q);
	
	enqueue(&Q, 'A');
	enqueue(&Q, 'B');
	enqueue(&Q, 'C');
	enqueue(&Q, 'D');
	
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);
	
	enqueue(&Q, 'E');
	enqueue(&Q, 'F');
	enqueue(&Q, 'G');
	enqueue(&Q, 'H');
	enqueue(&Q, 'I');
	
	display(&Q);
	
	printf("\nfront: %c", peek(Q));
	
	return 0;
}
