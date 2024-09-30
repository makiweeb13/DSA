// Computer Word Implementation of Sets
#include <stdio.h>

typedef enum {
	FALSE, TRUE
} boolean;

typedef unsigned char Set;

void initSet(Set *A);
void insertElem(Set *A, int elem);
void deleteElem(Set *A, int elem);
boolean member(Set A, int elem);
Set unionSet(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void displaySet(Set A);

void initSet(Set *A) {
	*A = 0;
}

void insertElem(Set *A, int elem) {
	unsigned char mask = 1 << elem-1;
	*A |= mask;
}

void deleteElem(Set *A, int elem) {
	unsigned char mask = 1 << elem-1;
	*A ^= mask;
}

boolean member(Set A, int elem) {
	unsigned char mask = 1 << elem-1;
	return (A&mask) != 0 ? TRUE : FALSE;
}

Set unionSet(Set A, Set B) {
	return A|B;
}

Set intersection(Set A, Set B) {
	return A&B;
}

Set difference(Set A, Set B) {
	return (A^B)&A;
}

void displaySet(Set A) {
	int n = 1;
	char mask = 1;
	printf("{ ");
	while (A != 0) {
		if ((A&mask) != 0) printf("%d ", n);
		n++;
		A = A >> 1;
	}
	printf("}\n");
}
