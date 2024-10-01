#include <stdio.h>
//#include "OpenHashing.h"
#include "ClosedHashing.h"

int main() {
	Dictionary D;
	
	initDictionary(D);
	
	insertElem(D, 14);
	insertElem(D, 25);
	insertElem(D, 66);
	insertElem(D, 54);
	insertElem(D, 95);
	insertElem(D, 41);
	insertElem(D, 67);
	insertElem(D, 89);
	insertElem(D, 90);
	insertElem(D, 99);
	insertElem(D, 44);
	insertElem(D, 64);
	insertElem(D, 73);
	
	deleteElem(D, 44);
	deleteElem(D, 41);
	deleteElem(D, 54);
	
	display(D);
	
	printf("\nisMember(%d): %s", 90, isMember(D, 90) == 1 ? "true" : "false");
	printf("\nisMember(%d): %s", 87, isMember(D, 87) == 1 ? "true" : "false");
	
	return 0;
}
