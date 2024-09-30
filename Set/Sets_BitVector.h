// Bit Vector Implementation of Set
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef enum {
	FALSE, TRUE
} boolean;

typedef int Set[MAX];

void initSet(Set A);
void insertElem(Set A, int elem);
void deleteElem(Set A, int elem);
boolean member(Set A, int elem);
int* unionSet(Set A, Set B);
int* intersection(Set A, Set B);
int* difference(Set A, Set B);
void displaySet(Set A);

void initSet(Set A) {
	int i;
	for (i = 0; i < MAX; i++) {
		A[i] = 0;
	}
}

void insertElem(Set A, int elem) {
	A[elem-1] = 1;
}

void deleteElem(Set A, int elem) {
	A[elem-1] = 0;
}

boolean member(Set A, int elem) {
	return (A[elem-1] == 1) ? TRUE : FALSE;
}

int* unionSet(Set A, Set B) {
	int i, *newSet = (int*) malloc(sizeof(Set));
	for (i = 0; i < MAX; i++) {
		newSet[i] = A[i] == 1 || B[i] == 1;
	}
	return newSet;
}

int* intersection(Set A, Set B) {
	int i, *newSet = (int*) malloc(sizeof(Set));
	for (i = 0; i < MAX; i++) {
		newSet[i] = A[i] == 1 && B[i] == 1;
	}
	return newSet;
}

int* difference(Set A, Set B) {
	int i, *newSet = (int*) malloc(sizeof(Set));
	for (i = 0; i < MAX; i++) {
		newSet[i] = A[i] == 1 && B[i] == 0;
	}
	return newSet;
}

void displaySet(Set A) {
	int i;
	printf("{ ");
	for (i = 0; i < MAX; i++) {
		if (A[i] == 1) {
			printf("%d ", i+1);
		}
	}
	printf("}\n");
}
