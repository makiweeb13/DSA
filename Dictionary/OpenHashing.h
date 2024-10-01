// Open Hashing Implementation of Dictionary

#define MAX 10
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	FALSE, TRUE
} boolean;

typedef struct node {
	int data;
	struct node *next;
} *Node;

typedef Node Dictionary[MAX];

int hash(int elem); // groups elements according to their ones place
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
		A[i] = NULL;
	}
}

void insertElem(Dictionary A, int elem) {
	Node *trav, newNode = (Node) malloc(sizeof(struct node));
	for (trav = &(A[hash(elem)]); *trav != NULL; trav = &(*trav)->next) {}
	if (newNode != NULL) {
		newNode->data = elem;
		newNode->next = NULL;
		*trav = newNode;
	}
	
}

void deleteElem(Dictionary A, int elem) {
	Node *trav, temp;
	for (trav = &(A[hash(elem)]); (*trav)->data != elem && *trav != NULL; trav = &(*trav)->next) {}
	if (*trav != NULL) {
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

boolean isMember(Dictionary A, int elem) {
	Node trav;
	for (trav = A[hash(elem)]; trav != NULL && trav->data != elem; trav = trav->next) {}
	return trav == NULL ? FALSE : TRUE;
}

void display(Dictionary A) {
	Node trav;
	int i;
	for (i = 0; i < MAX; i++) {
		printf("%d: ", i);
		for (trav = A[i]; trav != NULL; trav = trav->next) {
			printf("[%d] -> ", trav->data);
		}
		printf("[]\n");
	}
}
