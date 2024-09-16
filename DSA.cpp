#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 4
#define HEAP_SIZE 15
#define TABLE_SIZE 10
#define MAX_TITLE 40

// DATA STRUCTURE:

// STACK Structures
typedef struct {
	int *stack;
	int top;
} AStack; // array stack implementation

typedef struct stack_node {
	int elem;
	struct stack_node *next;
} *LStack; // linked list stack implementation

// QUEUE Structures
typedef struct {
	int *queue;
	int head;
	int tail;
} AQueue; // array queue implementation

typedef struct queue_node {
	int elem;
	struct queue_node *next;
} *LQueue; // linked list queue implementation

// PRIORITY QUEUE

typedef struct {
	int count;
	int *heap_arr;
} PriorityQueue;

// HASH TABLE
typedef struct novel {
	char title[MAX_TITLE];
	struct novel *next;
} Novel;

Novel *danmei[TABLE_SIZE];

// GRAPH: Adjacency Matrix Implementation
typedef struct {
	int node_count;
	int **edges;	
} Graph;

// GRAPH: Adjancency List Implementation
typedef struct graph_node {
	int node;
	struct graph_node *next;
} Node;

typedef struct {
	Node *list[50];
	int node_count;
} GraphAL;

// Stack array implementation functions
void initAStack(AStack *A); 
void pushAStack(AStack *A, int data); // adds an element at the top of the stack
void displayAStack(AStack A);
int popAStack(AStack *A); // removes and returns last inserted element
int isFullAStack(AStack A);
int isEmptyAStack(AStack A);

// Stack linked list implementation functions
void pushLStack(LStack *L, int elem); // inserts a new node at the beginning of the stack
void displayLStack(LStack L);
int popLStack(LStack *L); // deletes the first node and returns the element deleted
void freeStack(LStack *L);
int peekLStack(LStack L);
int isEmptyLStack(LStack L);

// Queue array implementation functions
void initAQueue(AQueue *A);
void displayAQueue(AQueue A);
void enqueue_A(AQueue *A, int elem);
int dequeue_A(AQueue *A);
int getNextPos(int pos);
int isEmptyAQueue(AQueue A);
int isFullAQueue(AQueue A);
int frontAQueue(AQueue A);

// Queue linked list implementation functions
void enqueue_L(LQueue *head, LQueue *tail, int elem);
int dequeue_L(LQueue *head, LQueue *tail);
void displayLQueue(LQueue head, LQueue tail);
void freeQueue(LQueue *head);

// Priority Queue functions
void init_PQ(PriorityQueue *pq);
int isFull_PQ(PriorityQueue pq);
void display_PQ(PriorityQueue pq);
void enqueue_min(PriorityQueue *pq, int elem);
void siftup_min(PriorityQueue *pq, int i);
void siftdown_min(PriorityQueue *pq, int i);
int getRoot(PriorityQueue pq);
int dequeue_min(PriorityQueue *pq);
void siftdown_max(PriorityQueue *pq, int i);
void max_heapify(PriorityQueue *pq);
void min_heapify(PriorityQueue *pq);

// Hash table functions
int hash(char title[]);
void init_HashTable(Novel *table[]);
void display_HashTable(Novel *table[]);
void insert_HashTable(Novel *table[], Novel *novel);
int search_HashTable(Novel *table[], char title[]);
void delete_HashTable(Novel *table[], char title[]);

// Graph Adjacency Matrix implementation functions
Graph *create_graph(int node_count);
void delete_graph(Graph *g);
void display_graph(Graph *g);
bool add_edge(Graph *g, unsigned int src, unsigned int dest);
bool has_edge(Graph *g, unsigned int src, unsigned int dest);

// Graph Adjacency List implementation functions
GraphAL *init_graph(int node_count);
void free_graph(GraphAL *g);
void display_graphAl(GraphAL *g);
bool addEdge(GraphAL *g, int src, int des);
bool hasEdge(GraphAL *g, int src, int des);

// ALGORITHMS:

// Binary Search
int binarySearch(int arr[], int target, int size);

// Merge Sort
void mergeSort(int arr[], int size);
void merge(int leftArr[], int rightArr[], int arr[], int left_size, int right_size);

int main() {
	int i;
	printf("\n---------------------------------\n");
	printf("STACK : Array Implementation\n");
	
	AStack stack_arr;
	
	// initialize array stack
	initAStack(&stack_arr);
	
	// insert elements at the top (push)
	for (i = 0; i < 5; i++) {
		pushAStack(&stack_arr, i + 1);
		displayAStack(stack_arr);
	}
	
	// deletes last inserted element (pop)
	for (i = 0; i < 4; i++) {
		printf("pop: %d = ", popAStack(&stack_arr));
		displayAStack(stack_arr);
	}
	
	free(stack_arr.stack);
	
	printf("\n---------------------------------\n");
	printf("STACK : Linked List Implementation\n");
	
	LStack top = NULL;
	
	// insert elements at the top (push)
	for (i = 0; i < 5; i++) {
		pushLStack(&top, i+1);
		displayLStack(top);
	}
	
	// remove element from the top (pop)
	for (i = 0; i < 5; i++) {
		printf("pop: %d = ", popLStack(&top));
		displayLStack(top);
	}
	
	freeStack(&top);
	
	printf("\n---------------------------------\n");
	printf("QUEUE : Array Implementation\n");
	
	AQueue queue_arr;
	
	// initialize array queue
	initAQueue(&queue_arr);
	
	// enqueue
	for (i = 0; i < 4; i++) {
		enqueue_A(&queue_arr, i+1);
		printf("enqueue: %d head: %d tail: %d = ", i+1, queue_arr.head, queue_arr.tail);
		displayAQueue(queue_arr);
	}
	
	// dequeue
	for (i = 0; i < 2; i++) {
		printf("dequeue: %d ", dequeue_A(&queue_arr));
		printf("head: %d tail: %d = ", queue_arr.head, queue_arr.tail);
		displayAQueue(queue_arr);
	}
	
	// enqueue
	for (i = 4; i < 7; i++) {
		enqueue_A(&queue_arr, i+1);
		printf("enqueue: %d head: %d tail: %d = ", i+1, queue_arr.head, queue_arr.tail);
		displayAQueue(queue_arr);
	}
	
	// dequeue
	for (i = 0; i < 4; i++) {
		printf("dequeue: %d ", dequeue_A(&queue_arr));
		printf("head: %d tail: %d = ", queue_arr.head, queue_arr.tail);
		displayAQueue(queue_arr);
	}
	
	free(queue_arr.queue);
	
	printf("\n---------------------------------\n");
	printf("QUEUE : Linked List Implementation\n");
	
	LQueue head = NULL, tail = NULL;
	
	// enqueue
	for (i = 0; i < 5; i++) {
		enqueue_L(&head, &tail, i+1);
		displayLQueue(head, tail);
	}
	
	// dequeue
	for (i = 0; i < 5; i++) {
		printf("dequeue: %d = ", dequeue_L(&head, &tail));
		displayLQueue(head, tail);
	}
	
	freeQueue(&head);
	
	printf("\n---------------------------------\n");
	printf("PRIORITY QUEUE : Binary Heap Implementation\n");
	
	PriorityQueue pq;
	
	init_PQ(&pq);
	
	for (i = 15; i >= 1; i--) {
		enqueue_min(&pq, i);
		display_PQ(pq);
	}
	
	max_heapify(&pq);
	display_PQ(pq);
	
	min_heapify(&pq);
	display_PQ(pq);
	
	for (i = 15; i > 1; i--) {
		printf("dequeue: %d = ", dequeue_min(&pq));
		display_PQ(pq);
	}
	
	free(pq.heap_arr);
	
	printf("\n---------------------------------\n");
	printf("Binary Search:\n");
	
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for (i = 0; i < 9; i++) {
		printf("[%d]", arr[i]);
	}
	printf("\n");
	
	printf("\nindex of 7: %d\n", binarySearch(arr, 7, 9));
	printf("\nindex of 0: %d\n", binarySearch(arr, 0, 9));
	
	printf("\n---------------------------------\n");
	printf("Hash Table:\n");
	
	init_HashTable(danmei);
	
	Novel novel1 = {"Grandmaster of Demonic Cultivation", NULL};
	Novel novel2 = {"Heaven Official's Blessing", NULL};
	Novel novel3 = {"Scum Villain's Self-Saving System", NULL};
	Novel novel4 = {"A Thousand Autumns", NULL};
	Novel novel5 = {"The Dumb Husky and his White Cat Shizun", NULL};
	Novel novel6 = {"Faraway Wanderers", NULL};
	Novel novel7 = {"Remnants of Filth", NULL};
	
	insert_HashTable(danmei, &novel1);
	insert_HashTable(danmei, &novel2);
	insert_HashTable(danmei, &novel3);
	insert_HashTable(danmei, &novel4);
	insert_HashTable(danmei, &novel5);
	insert_HashTable(danmei, &novel6);
	insert_HashTable(danmei, &novel7);
	
	display_HashTable(danmei);
	
	printf("\"A Thousand Autumns\" = %d\n", search_HashTable(danmei, (char*)"A Thousand Autumns"));
	printf("\"Faraway Wanderers\" = %d\n", search_HashTable(danmei, (char*)"Faraway Wanderers"));
	printf("\"Solo Leveling\" = %d\n", search_HashTable(danmei, (char*)"Solo Leveling"));
	
	printf("Delete \"Faraway Wanderers\":\n");
	delete_HashTable(danmei, (char*)"Faraway Wanderers");
	display_HashTable(danmei);
	
	printf("\n---------------------------------\n");
	printf("Graph: Adjacency Matrix Implementation\n");
	
	Graph *graph = create_graph(5);
	
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 3);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 2, 2);
	add_edge(graph, 3, 1);
	add_edge(graph, 4, 2);
	
	display_graph(graph);
	
	delete_graph(graph);
	
	printf("\n---------------------------------\n");
	printf("Graph: Adjacency List Implementation\n");
	
	GraphAL *g = init_graph(5);
	
	addEdge(g, 0, 2);
	addEdge(g, 0, 3);
	addEdge(g, 0, 3);
	addEdge(g, 1, 5);
	addEdge(g, 1, 4);
	addEdge(g, 2, 4);
	addEdge(g, 2, 2);
	addEdge(g, 3, 1);
	addEdge(g, 4, 2);
	
	display_graphAl(g);
	free_graph(g); 
	
	printf("\n---------------------------------\n");
	printf("Merge Sort:\n"); 
	
	int size = 8;
	int arrToSort[size] = {8, 2, 5, 3, 4, 7, 6, 1};
	
	mergeSort(arrToSort, size);
	
	for (i = 0; i < size; i++) {
		printf("[%d]", arrToSort[i]);
	}
	printf("\n");
	
	return 0;
}

void initAStack(AStack *A) {
	A->stack = (int*) malloc(sizeof(int) * MAX);
	A->top = -1;
}

void pushAStack(AStack *A, int data) {
	if (isFullAStack(*A)) {
		printf("Stack is full.\n");
		return;
	}
	A->top++;
	A->stack[A->top] = data;
}

void displayAStack(AStack A) {
	if (isEmptyAStack(A)) {
		printf("Stack is empty.\n");
		return;
	}
	int i;
	for (i = 0; i <= A.top; i++) {
		printf("[%d]", A.stack[i]);
	}
	printf("\n");
}

int popAStack(AStack *A) {
	if (isEmptyAStack(*A)) {
		printf("Stack is already empty.");
		return -1;
	}
	int value = A->stack[A->top];
	A->top--;
	return value;
}

int isFullAStack(AStack A) {
	return A.top == MAX - 1 ? 1 : 0;
}

int isEmptyAStack(AStack A) {
	return A.top == -1 ? 1 : 0;
}

void pushLStack(LStack *L, int elem) {
	LStack newNode = (LStack) malloc(sizeof(struct stack_node));
	if (newNode == NULL) {
		printf("Failed to allocate memory.\n");
		exit(1);
	}
	newNode->elem = elem;
	newNode->next = *L;
	*L = newNode;
}

void displayLStack(LStack L) {
	if (isEmptyLStack(L)) {
		printf("Stack is empty.\n");
		return;
	}
	LStack trav;
	for (trav = L; trav != NULL; trav = trav->next) {
		printf("[%d]->", trav->elem);
	}
	printf("[.]\n");
}

void freeStack(LStack *L) {
	LStack temp, trav = *L;
	while (trav != NULL) {
		temp = trav;
		trav = trav->next;
		free(temp);
	}
}

int popLStack(LStack *L) {
	if (isEmptyLStack(*L)) {
		return -1;
	}
	LStack temp = *L;
	int val = temp->elem;
	
	*L = temp->next;
	free(temp);
	temp = NULL;
	
	return val;
}

int peekLStack(LStack L) {
	if (L == NULL) {
		printf("Stack is empty.\n");
		exit(1);
	}
	return L->elem;
}

int isEmptyLStack(LStack L) {
	return L == NULL ? 1 : 0;
}

void initAQueue(AQueue *A) {
	A->queue = (int*) malloc(sizeof(int) * MAX);
	A->head = -1;
	A->tail = -1;
}

void displayAQueue(AQueue A) {
	if (isEmptyAQueue(A)) {
		printf("Queue is empty.\n");
		return;
	}
	int i = A.head, j = A.tail;
	
	if (i <= j) {
		for (i; i <= j; i++) {
		printf("[%d]", A.queue[i]);
		}
	} else {
		for (i; i < MAX; i++) {
		printf("[%d]", A.queue[i]);
		}
		for (i = 0; i <= j; i++) {
		printf("[%d]", A.queue[i]);
		}
	}
	
	printf("\n");
}

int getNextPos(int pos) {
	return (pos + 1) % MAX;
}

void enqueue_A(AQueue *A, int elem) {
	if (isFullAQueue(*A)) {
		return;
	} else if (isEmptyAQueue(*A)) {
		A->head = 0;
		A->tail = 0;
	} else {
		A->tail = getNextPos(A->tail);
	}
	A->queue[A->tail] = elem;
}

int dequeue_A(AQueue *A) {
	int val = -1;
	if (isEmptyAQueue(*A)) {
		return val;
	}
	if (A->head == A->tail) {
		A->head = -1;
		A->tail = -1;
	} else {
		val = A->queue[A->head];
		A->head = getNextPos(A->head);
	}
	return val;
}

int isEmptyAQueue(AQueue A) {
	return A.head == -1 && A.tail == -1 ? 1 : 0;
}

int isFullAQueue(AQueue A) {
	return getNextPos(A.tail) == A.head ? 1 : 0;
}

int frontAQueue(AQueue A) {
	return A.queue[A.head];
}

void enqueue_L(LQueue *head, LQueue *tail, int elem) {
	LQueue newNode = (LQueue) malloc(sizeof(struct queue_node));
	
	if (newNode == NULL) {
		printf("Failed to allocate memory.");
		return;
	}
	newNode->elem = elem;
	newNode->next = NULL;
	if (*head == NULL && *tail == NULL) {
		*head = *tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	*tail = newNode;
}

int dequeue_L(LQueue *head, LQueue *tail) {
	LQueue temp = *head;
	int val = -1;
	if (*head == NULL) return val;
	
	val = (*head)->elem;
	if (*head == *tail) {
		*head = *tail = NULL;
	} else {
		*head = (*head)->next;
	}
	
	free(temp);
	return val;
}

void displayLQueue(LQueue head, LQueue tail) {
	LQueue trav;
	if (head == NULL && tail == NULL) {
		printf("Queue is empty.\n");
		return;
	}
	for (trav = head; trav != NULL; trav = trav->next) {
		printf("[%d]->", trav->elem);
	}
	printf("[.]\n");
}

void freeQueue(LQueue *head) {
	LQueue temp, trav = *head;
	while (trav != NULL) {
		temp = trav;
		trav = trav->next;
		free(temp);
	}
}

void init_PQ(PriorityQueue *pq) {
	pq->count = 0;
	pq->heap_arr = (int*) malloc(sizeof(int) * HEAP_SIZE);
	if (pq->heap_arr == NULL) {
		printf("Failed to allocate memory.");
		return;
	}
}

void enqueue_min(PriorityQueue *pq, int elem) {
	int i;
	
	if (isFull_PQ(*pq)) {
		printf("Priority Queue is full.\n");
		return;
	}
	
	pq->heap_arr[pq->count] = elem;
	pq->count++;
	
	siftup_min(pq, pq->count - 1);
}

int isFull_PQ(PriorityQueue pq) {
	if (pq.count + 1 == HEAP_SIZE) {
		return 1;
	}
	return 0;
}

void display_PQ(PriorityQueue pq) {
	int i;
	
	if (pq.count == 0) {
		printf("Priority Queue is empty.\n");
		return;
	}
	
	for (i = 0; i < pq.count; i++) {
		printf("[%d] ", pq.heap_arr[i]);
	}
	
	printf("\n");
}

void siftup_min(PriorityQueue *pq, int i) {
	int parent = (i-1)/2, temp;
	while (i != 0 && pq->heap_arr[i] < pq->heap_arr[parent]) {
		temp = pq->heap_arr[i];
		pq->heap_arr[i] = pq->heap_arr[parent];
		pq->heap_arr[parent] = temp;
		i = parent;
		parent = (i-1)/2;
	}
}

void siftdown_min(PriorityQueue *pq, int i) {
	int left = (2*i) + 1;
	int right = left + 1;
	int smallest, temp;
	
	while ((left < pq->count && pq->heap_arr[i] > pq->heap_arr[left]) || 
		   (right < pq->count && pq->heap_arr[i] > pq->heap_arr[right])) {
		smallest = pq->heap_arr[left] < pq->heap_arr[right] || right >= pq->count ? left : right;
		temp = pq->heap_arr[i];
		pq->heap_arr[i] = pq->heap_arr[smallest];
		pq->heap_arr[smallest] = temp;
		i = smallest;
		left = (2*i) + 1;
		right = left + 1;
		
	}
}

int getRoot(PriorityQueue pq) {
	return pq.heap_arr[0];
}

int dequeue_min(PriorityQueue *pq) {
	int val, temp;
	
	if (pq->count == 0) {
		return -1;
	}
	
	val = pq->heap_arr[0];
	pq->heap_arr[0] = pq->heap_arr[pq->count-1];
	pq->count--;
	siftdown_min(pq, 0);
	return val;
}

void siftdown_max(PriorityQueue *pq, int i) {
	int left = (2*i) + 1;
	int right = left + 1;
	int largest, temp;
	
	while ((left < pq->count && pq->heap_arr[i] < pq->heap_arr[left]) || 
		   (right < pq->count && pq->heap_arr[i] < pq->heap_arr[right])) {
		largest = pq->heap_arr[left] > pq->heap_arr[right] || right >= pq->count ? left : right;
		temp = pq->heap_arr[i];
		pq->heap_arr[i] = pq->heap_arr[largest];
		pq->heap_arr[largest] = temp;
		i = largest;
		left = (2*i) + 1;
		right = left + 1;
	}
}

void max_heapify(PriorityQueue *pq) {
	int i = pq->count-1;
	for (i; i >= 0; i--) {
		siftdown_max(pq, i);
	}
}

void min_heapify(PriorityQueue *pq) {
	int i = pq->count-1;
	for (i; i >= 0; i--) {
		siftdown_min(pq, i);
	}
}

int binarySearch(int arr[], int target, int size) {
	int i = 0, j = size - 1;
	
	while (i <= j) {
		int mid = i + (j - i) / 2;
		int val = arr[mid];
		
		printf("\nmiddle: %d", val);
		
		if (val < target) i = mid + 1;
		else if (val > target) j = mid - 1;
		else return mid;
	}
	
	return -1;
}

int hash(char title[]) {
	int i, length = strlen(title);
	unsigned int hashVal = 0;
	
	for (i = 0; i < length; i++) {
		hashVal +=  title[i] + i;
	}
	
	return hashVal % TABLE_SIZE;
}

void init_HashTable(Novel *table[]) {
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
	}
}

void display_HashTable(Novel *table[]) {
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		Novel *ptr;
		ptr = table[i];
		printf("| ");
		if (table[i] == NULL) {
			printf("%-40s", "---");
			printf(" |");
		}
		while(ptr != NULL) {
			printf("%-40s", ptr->title);
			printf(" |");
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void insert_HashTable(Novel *table[], Novel *novel) {
	Novel **ptr;
	int n = hash(novel->title);

	for (ptr = &table[n]; (*ptr) != NULL; ptr = &(*ptr)->next) {}
	
	*ptr = novel;
}

int search_HashTable(Novel *table[], char title[]) {
	Novel *ptr;
	int n = hash(title);
	
	for (ptr = table[n]; ptr != NULL; ptr = ptr->next) {
		if (strcmp(ptr->title, title) == 0) {
			return n;
		} 
	}
	return -1;
}

void delete_HashTable(Novel *table[], char title[]) {
	Novel *temp, **ptr;
	int n = hash(title);
	
	for (ptr = &table[n]; (*ptr) != NULL && strcmp((*ptr)->title, title) != 0; ptr = &(*ptr)->next) {}
	temp = *ptr;
	
	if (temp != NULL) {
		*ptr = temp->next;
		temp = NULL;
	}
}

Graph *create_graph(int node_count) {
	
	Graph *g = (Graph*) malloc(sizeof(Graph));
	if (g == NULL) return NULL;
	
	g->node_count = node_count;
	g->edges = (int**) calloc(node_count, sizeof(int*));
	
	if (g->edges == NULL) {
		free(g);
		return NULL;
	}
	
	int i;
	for (i = 0; i < g->node_count; i++) {
		g->edges[i] = (int*) calloc(node_count, sizeof(int));
		if (g->edges[i] ==NULL) {
			delete_graph(g);
			return NULL;
		}
	}
	return g;
}

void delete_graph(Graph *g) {
	int i;
	
	if (g->edges == NULL) {
		free(g);
		return;
	}
	
	for (i = 0; i < g->node_count; i++) {
		if (g->edges[i] != NULL) free(g->edges[i]);
	}
	
	free(g->edges);
	free(g);
}

void display_graph(Graph *g) {
	int col, row;
	
	printf("\n");
	for (col = 0; col < g->node_count; col++) {
		for (row = 0; row < g->node_count; row++) {
			printf("[%d]", g->edges[col][row]);
		}
		printf("\n");
	}
}

bool add_edge(Graph *g, unsigned int src, unsigned int dest) {
	if (has_edge(g, src, dest)) {
		return false;
	}
	g->edges[src][dest] = 1;
	return true;
}

bool has_edge(Graph *g, unsigned int src, unsigned int dest) {
	if (g->edges[src][dest] != 0) {
		return true;
	}
	return false;
}

GraphAL *init_graph(int node_count) {
	GraphAL *g = (GraphAL*) malloc(sizeof(GraphAL));
	if (g == NULL) return NULL;
	
	g->node_count = node_count;
	
	if (g->list == NULL) {
		free(g);
		return NULL;
	}
	
	int i;
	for (i = 0; i < node_count; i++) {
		Node *newNode = (Node*) malloc(sizeof(Node));
		if (newNode == NULL) {
			free(g);
			return NULL;
		}
		newNode->node = i+1;
		newNode->next = NULL;
		g->list[i] = newNode;
	}
	return g; 
}
void free_graph(GraphAL *g) {
	Node *temp, *ptr;
	int i;
	for (i = 0; i < g->node_count; i++) {
		ptr = g->list[i];
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
	}
}

void display_graphAl(GraphAL *g) {
	Node *ptr;
	int i;
	for (i = 0; i < g->node_count; i++) {
		ptr = g->list[i];
		while (ptr != NULL) {
			printf("%d -> ", ptr->node);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

bool addEdge(GraphAL *g, int src, int des) {
	
	if (hasEdge(g, src, des)) return false;
	
	Node *newNode = (Node*) malloc(sizeof(Node));

	if (newNode == NULL) return false;
	
	newNode->node = des;
	newNode->next = NULL;
	
	Node **ptr;
	for (ptr = &g->list[src]; (*ptr) != NULL; ptr = &(*ptr)->next) {}
	
	*ptr = newNode;
	
	return true;
}

bool hasEdge(GraphAL *g, int src, int des) {
	Node *ptr;
	for (ptr = g->list[src]->next; ptr != NULL; ptr = ptr->next) {
		if (ptr->node == des) return true;
	} 
	return false;
}

void mergeSort(int arr[], int size) {
	if (size <= 1) return; // base case
	
	int middle = size/2; 
	
	int left[middle];
	int right[size - middle];
	
	int i = 0, j = 0;
	
	for (; i < size; i++) {
		if (i < middle) {
			left[i] = arr[i];
		} else {
			right[j] = arr[i];
			j++;
		}
	}
	
	mergeSort(left, middle);
	mergeSort(right, size - middle);
	merge(left, right, arr, middle, size - middle);
}
void merge(int leftArr[], int rightArr[], int arr[], int left_size, int right_size) {
	int i = 0, l = 0, r = 0;
	
	while (l < left_size && r < right_size) {
		if (leftArr[l] < rightArr[r]) {
			arr[i] = leftArr[l];
			l++;
		} else {
			arr[i] = rightArr[r];
			r++;
		}
		i++;
	}
	
	while (l < left_size) {
		arr[i] = leftArr[l];
		i++;
		l++;
	}
	
	while (r < right_size) {
		arr[i] = rightArr[r];
		i++;
		r++;
	}
}
