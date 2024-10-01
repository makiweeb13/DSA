// Closed Hashing Implementation of Dictionary

#include <stdio.h>
#define MAX 20
#define EMPTY -1
#define DELETED -2

typedef enum {
	FALSE, TRUE
} boolean;

typedef int Dictionary[MAX]; // will only contain positive integers

int hash(int elem); // hashing according to their ones place
void initDictionary(Dictionary A);
void insertElem(Dictionary A, int elem);
void deleteElem(Dictionary A, int elem);
boolean isMember(Dictionary A, int elem);
void display(Dictionary A);

int hash(int elem) {
	return elem%10;
}

void initDictionary(Dictionary A) {
	int i;
	for (i = 0; i < MAX; i++) {
		A[i] = EMPTY;
	}
}

void insertElem(Dictionary A, int elem) {
	int i = hash(elem), count = 0;
	while (A[i] != EMPTY && count < MAX) {
		i = (i+1) % MAX;
		count++;
	}
	if (count < MAX) {
		A[i] = elem;
	}
}

void deleteElem(Dictionary A, int elem) {
	int i = hash(elem), count = 0;
	while (A[i] != elem && count < MAX) {
		i = (i+1) % MAX;
		count++;
	}
	if (count < MAX) {
		A[i] = DELETED;
	}
}

boolean isMember(Dictionary A, int elem) {
	int i = hash(elem), count = 0;
	while (A[i] != elem && count < MAX) {
		i = (i+1) % MAX;
		count++;
	}
	return count < MAX ? TRUE : FALSE;
}

void display(Dictionary A) {
	int i;
	for (i = 0; i < MAX; i++) {
		printf("[");
		if (A[i] == EMPTY) printf("EMPTY");
		else if (A[i] == DELETED) printf("DELETED");
		else printf("%d", A[i]);
		printf("]\n");
	}
}
