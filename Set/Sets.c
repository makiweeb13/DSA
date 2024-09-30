#include <stdio.h>
//#include "Sets_ComputerWord.h"
#include "Sets_BitVector.h"

int main() {
//	For Computer Word:

//	printf("A: ");
//	Set A;
//	initSet(&A);
//	insertElem(&A, 5);
//	insertElem(&A, 3);
//	insertElem(&A, 2);
//	insertElem(&A, 1);
//	deleteElem(&A, 5);
//	displaySet(A);
//	
//	printf("B: ");
//	Set B;
//	initSet(&B);
//	insertElem(&B, 3);
//	insertElem(&B, 2);
//	insertElem(&B, 6);
//	insertElem(&B, 8);
//	displaySet(B);

//	For Bit Vector:

	printf("A: ");
	Set A;
	initSet(A);
	insertElem(A, 5);
	insertElem(A, 3);
	insertElem(A, 2);
	insertElem(A, 1);
	deleteElem(A, 5);
	displaySet(A);
	
	printf("B: ");
	Set B;
	initSet(B);
	insertElem(B, 3);
	insertElem(B, 2);
	insertElem(B, 6);
	insertElem(B, 8);
	displaySet(B);
	
	printf("union: ");
	displaySet(unionSet(A, B));
	
	printf("intersection: ");
	displaySet(intersection(A, B));
	
	printf("A-B: ");
	displaySet(difference(A, B));
	
	printf("B-A: ");
	displaySet(difference(B, A));
	
	printf("%d\n", member(A, 1));
	
	return 0;
}
