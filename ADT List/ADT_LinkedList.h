// ADT Operations using LinkedList Implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char elem;
	struct node *next;
} *List, nodeType;

typedef enum {
	FALSE,
	TRUE
} boolean;

void initList(List *L);
void displayList(List L);
void insertFirst(List *L, char elem);
void insertLast(List *L, char elem);
void insertAt(List *L, char elem, int pos);
void insertSorted(List *L, char elem);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAll(List *L);
boolean isEqualSorted(List L1, List L2);
boolean isEqualUnsorted(List L1, List L2);
List unionSorted(List A, List B);
List unionUnsorted(List A, List B);

void initList(List *L) {
	*L = NULL;
}

void displayList(List L) {
	List trav;
	for (trav = L; trav != NULL; trav = trav->next) {
		printf("%c", trav->elem);
	}
}

void insertFirst(List *L, char elem) {
	List newNode = (List)malloc(sizeof(nodeType));
	if (newNode != NULL) {
		newNode->elem = elem;
		newNode->next = *L;
		*L = newNode;
	}
}

void insertLast(List *L, char elem) {
	List newNode = (List)malloc(sizeof(nodeType));
	if (newNode != NULL) {
		newNode->elem = elem;
		newNode->next = NULL;
		
		List *trav;
		for (trav = L; (*trav) != NULL; trav = &(*trav)->next) {}
		*trav = newNode;
	}
}

void insertAt(List *L, char elem, int pos) {
	List newNode = (List)malloc(sizeof(nodeType));
	if (newNode != NULL) {
		List *trav;
		int i;
		for (trav = L, i = 0; (*trav) != NULL && i < pos; trav = &(*trav)->next, i++) {}
		if (i == pos) {
			newNode->elem = elem;
			newNode->next = (*trav)->next;
			(*trav)->next = newNode;
		}
	}
}

void insertSorted(List *L, char elem) {
	List *trav;
	for (trav = L; *trav != NULL && elem > (*trav)->elem; trav = &(*trav)->next) {}
	
	List newNode = (List) malloc(sizeof(struct node));
	if (newNode != NULL) {
		newNode->elem = elem;
		newNode->next = *trav;
		*trav = newNode;
	}
}

void deleteFirst(List *L) {
	if (*L != NULL) {
		List temp = *L;
		*L = temp->next;
		free(temp);
	}
}

void deleteLast(List *L) {
	if (*L == NULL) return;
	List *trav;
	for (trav = L; (*trav)->next != NULL; trav = &(*trav)->next) {}
	free(*trav);
	*trav = NULL;
}

void deleteAll(List *L) {
	List *trav, temp;
	
	for (trav = L; (*trav) != NULL; ) {
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

// works only on unique lists
boolean isEqualSorted(List L1, List L2) {
	List trav1, trav2;
	
	for (trav1 = L1, trav2 = L2; (trav1 != NULL || trav2 != NULL) && trav1->elem == trav2->elem; trav1 = trav1->next, trav2 = trav2->next) {}
	
	return (trav1 == NULL && trav2 == NULL) ? TRUE : FALSE;
}

// works only on unique lists
boolean isEqualUnsorted(List L1, List L2) {
	List trav1, trav2;
	
	for (trav1 = L1; trav1 != NULL; trav1 = trav1->next) {
		for (trav2 = L2; trav2 != NULL && trav1->elem != trav2->elem; trav2 = trav2->next) {}
		if (trav2 == NULL) return FALSE;
	}
	
	return TRUE;
}

List unionSorted(List A, List B) {
	List L = NULL, *Lptr = &L, trav1, trav2;
	
	for (trav1 = A, trav2 = B; trav1 != NULL || trav2 != NULL; ) {
		
		List temp = (List) malloc(sizeof(nodeType));
		
		if (temp == NULL) return L;
		
		if (trav1 == NULL || trav1->elem > trav2->elem) {
			temp->elem = trav2->elem;
			trav2 = trav2->next;
		}
		else if (trav2 == NULL || trav1->elem < trav2->elem) {
			temp->elem = trav1->elem;
			trav1 = trav1->next;
		}
		else {
			temp->elem = trav1->elem;
			trav1 = trav1->next;
			trav2 = trav2->next;
		}
		
		temp->next = NULL;
		*Lptr = temp;
		Lptr = &(*Lptr)->next;
	}
	
	return L;
}

List unionUnsorted(List A, List B) {
	List L = NULL, *Lptr, trav1, trav2;
	
	for (trav1 = A, trav2 = B; trav1 != NULL || trav2 != NULL; ) {
		
		boolean containsA = FALSE, containsB = FALSE;
		
		for (Lptr = &L; (*Lptr) != NULL; Lptr = &(*Lptr)->next) {
			if (trav1 == NULL || (*Lptr)->elem == trav1->elem) containsA = TRUE;
			if (trav2 == NULL || (*Lptr)->elem == trav2->elem) containsB = TRUE;
		}
		
		if (containsA == FALSE) {
			List temp = (List) malloc(sizeof(nodeType));
			if (temp != NULL) {
				temp->elem = trav1->elem;
				temp->next = NULL;
				*Lptr = temp;
				Lptr = &(*Lptr)->next;
			}
		}
		if (containsB == FALSE) {
			List temp = (List) malloc(sizeof(nodeType));
			if (temp != NULL) {
				temp->elem = trav2->elem;
				temp->next = NULL;
				*Lptr = temp;
				Lptr = &(*Lptr)->next;
			}	
		}
		
		if (trav1 != NULL) trav1 = trav1->next;
		if (trav2 != NULL) trav2 = trav2->next;
	}
	
	return L;
}
