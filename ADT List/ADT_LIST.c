#include <stdio.h> 
#include <stdlib.h>
//#include "ADT_LinkedList.h"
//#include "ADT_ArrayList.h"
#include "ADT_CursorBased.h"

int main() {
	
	printf("WITH ");
	
	List title;
	
	initList(&title);
	
	insertFirst(&title, 'S');
	insertFirst(&title, 'N');
	insertFirst(&title, 'E');
	insertFirst(&title, 'V');
	insertFirst(&title, 'A');
	insertFirst(&title, 'E');
	insertFirst(&title, 'H');
	insertFirst(&title, '@');
	
	deleteLast(&title);
	
	insertLast(&title, ' ');
	insertLast(&title, 'O');
	insertLast(&title, 'F');
	insertLast(&title, 'F');
	insertLast(&title, 'I');
	insertLast(&title, 'C');
	insertLast(&title, 'I');
	insertLast(&title, 'A');
	insertLast(&title, 'L');
	insertLast(&title, 'S');
	
	insertAt(&title, '\'', 15);
	
	deleteFirst(&title);
	
	insertLast(&title, 'B');
	insertLast(&title, 'L');
	insertLast(&title, 'E');
	insertLast(&title, 'S');
	insertLast(&title, 'S');
	insertLast(&title, 'I');
	insertLast(&title, 'N');
	insertLast(&title, 'G');
	insertLast(&title, 'S');
	
	insertAt(&title, ' ', 16);
	insertAt(&title, ' ', 50);
	
	deleteLast(&title);
	
	displayList(title);
	deleteAll(&title);
	
	printf(", NO PATHS ARE BOUND!");
	
	return 0;
}
