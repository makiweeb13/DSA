// ADT Operations using Cursor-Based Implementation
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char data;
	int next;
} Node;

typedef struct {
	Node nodes[MAX];
	int avail;
} VirtualHeap;

typedef int List;
VirtualHeap VH;

void initList(List *L);
void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index); 
void displayList(List L);
void insertFirst(List *L, char elem);
void insertLast(List *L, char elem);
void insertAt(List *L, char elem, int pos);
void insertSorted(List *L, char elem);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAll(List *L);

void initVirtualHeap(VirtualHeap *VH) {
	int i, n = MAX-1;
	for (i = n; i >= 0; i--) {
		VH->nodes[i].next = i-1;
	}
	VH->avail = n;
}

void initList(List *L) {
	initVirtualHeap(&VH);
	*L = -1;
}

int allocSpace(VirtualHeap *VH) {
	int avail = VH->avail;
	if (VH->avail != -1) {
		VH->avail = VH->nodes[avail].next;
	}
	return avail;
}

void deallocSpace(VirtualHeap *VH, int index) {
	if (index >= 0 && index < MAX) {
		VH->nodes[index].next = VH->avail;
		VH->avail = index;
	}
}

void displayList(List L) {
	List trav;
	for (trav = L; trav != -1; trav = VH.nodes[trav].next) {
		printf("%c", VH.nodes[trav].data);
	}
}

void insertFirst(List *L, char elem) {
	List temp = allocSpace(&VH);
	if (temp != -1) {
		VH.nodes[temp].data = elem;
		VH.nodes[temp].next = *L;
		*L = temp;
	}
}

void insertLast(List *L, char elem) {
	List *trav;
	for (trav = L; *trav != -1; trav = &(VH.nodes[*trav].next)) {}
	
	List temp = allocSpace(&VH);
	if (temp != -1) {
		VH.nodes[temp].data = elem;
		VH.nodes[temp].next = -1;
		*trav = temp;
	}
}

void insertAt(List *L, char elem, int pos) {
	List *trav;
	int i;
	for (trav = L, i = 0; *trav != -1 && i < pos; trav = &(VH.nodes[*trav].next), i++) {}
	
	if (i == pos) {
		List temp = allocSpace(&VH);
		if (temp != -1) {
			VH.nodes[temp].data = elem;
			VH.nodes[temp].next = VH.nodes[*trav].next;
			VH.nodes[*trav].next = temp;
		}
	}
}

void deleteFirst(List *L) {
	if (*L != -1) {
		List temp = *L;
		*L = VH.nodes[temp].next;
		deallocSpace(&VH, temp);
	}
}

void deleteLast(List *L) {
	if (*L != -1) {
		List *trav;
		for (trav = L; VH.nodes[*trav].next != -1; trav = &(VH.nodes[*trav].next)) {}
		deallocSpace(&VH, *trav);
		*trav = -1;
	}
}

void deleteAll(List *L) {
	List *trav = L, temp;
	while (*trav != -1) {
		temp = *trav;
		*trav = VH.nodes[temp].next;
		deallocSpace(&VH, temp);
	}
}
