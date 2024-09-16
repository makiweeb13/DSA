// ADT Operations using ArrayList Implementation
#define MAX 100
#include <stdio.h>

typedef struct {
	char elem[MAX];
	int count;
} List;

void initList(List *L);
void displayList(List L);
void insertFirst(List *L, char elem);
void insertLast(List *L, char elem);
void insertAt(List *L, char elem, int pos);
void insertSorted(List *L, char elem);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAll(List *L);

void initList(List *L) {
	L->count = 0;
}

void displayList(List L) {
	int i;
	for (i = 0; i < L.count; i++) {
		printf("%c", L.elem[i]);
	}
}

void insertFirst(List *L, char elem) {
	if (L->count < MAX) {
		int i;
		for (i = L->count; i > 0; i--) {
			L->elem[i] = L->elem[i-1];
		}
		L->elem[i] = elem;
		L->count++;
	}
}

void insertLast(List *L, char elem) {
	if (L->count < MAX) {
		L->elem[L->count++] = elem;
	}
}

void insertAt(List *L, char elem, int pos) {
	if (L->count < MAX && pos >= 0 && pos < MAX) {
		int i;
		pos++;
		for (i = L->count; i > pos; i--) {
			L->elem[i] = L->elem[i-1];
		}
		L->elem[i] = elem;
		L->count++;
	}
}

void deleteFirst(List *L) {
	if (L->count != 0) {
		int i;
		L->count--;
		for (i = 0; i < L->count; i++) {
			L->elem[i] = L->elem[i+1];
		}
	}
}

void deleteLast(List *L) {
	L->count--;
}

void deleteAll(List *L) {
	L->count = 0;
}
