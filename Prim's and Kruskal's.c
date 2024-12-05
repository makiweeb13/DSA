#define MAX 5
#define MAX_SIZE 20
#define infinity 999
#include <stdio.h>

typedef int vertex;

typedef int LabelAdjMat[MAX][MAX];

typedef struct {
	int u, v;
	int weight;
} edgetype;

typedef struct {
	edgetype edges[MAX_SIZE];
	int lastNdx;
} minHeapOrList;

typedef struct {
	minHeapOrList eList;
	int cost;
} MST; // Prim's or Kruskal's

void insert(minHeapOrList *MH, edgetype E);
edgetype deleteMinHeap(minHeapOrList *MH);
void initHeap(minHeapOrList *MH);
void initMST(MST *M);
void initBitVector(LabelAdjMat L);
minHeapOrList createMinHeap(LabelAdjMat M);
void displayHeap(minHeapOrList MH);
MST Kruskals(LabelAdjMat A);
MST Prims(LabelAdjMat A, vertex startV);

int main() {
	// Given
	LabelAdjMat M = {{0, 1, 2, 11, 6}, {1, 0, infinity, 4, 5}, {2, infinity, 0, 5, 4}, {11, 4, 5, 0, infinity}, {6, 5, 4, infinity, 0}};
	
	// Getting Minimum Cost Spanning Tree
	
	printf("Kruskal's Algorithm:\n");
	MST K = Kruskals(M);
	displayHeap(K.eList);
	printf("cost: %d\n", K.cost);
	
	printf("Prim's Algorithm:\n");
	MST P = Prims(M, 1);
	displayHeap(P.eList);
	printf("cost: %d\n", P.cost);
	
	return 0;
}

void insert(minHeapOrList *MH, edgetype E) {
	if (MH->lastNdx < MAX_SIZE-1) {
		int i;
		for (i = MH->lastNdx; i >= 0 && MH->edges[i].weight > E.weight; i--) {
			MH->edges[i+1] = MH->edges[i];
		}
		MH->edges[i+1] = E;
		MH->lastNdx++;
	}
}

edgetype deleteMinHeap(minHeapOrList *MH) {
	edgetype min = MH->edges[0];
	int i;
	for (i = 0; i < MH->lastNdx; i++) {
		MH->edges[i] = MH->edges[i+1];
	}
	MH->lastNdx--;
	return min;
}

void initHeap(minHeapOrList *MH) {
	int i;
	for (i = 0; i < MAX_SIZE; i++) {
		MH->edges[i].u = 0;
		MH->edges[i].v = 0;
		MH->edges[i].weight = 0;
	}
	MH->lastNdx = -1;
}

void initMST(MST *M) {
	initHeap(&(M->eList));
	M->cost = 0;
}

void initBitVector(LabelAdjMat L) {
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			L[i][j] == 0;
		}
	}
}

minHeapOrList createMinHeap(LabelAdjMat M) {
	minHeapOrList MH;
	initHeap(&MH);
	int i, j;
	for (i = 0; i < MAX-1; i++) {
		for (j = i+1; j < MAX; j++) {
			if (M[i][j] != infinity) {
				edgetype E = {i, j, M[i][j]};
				insert(&MH, E);
			}
		}
	}
	return MH;
}

void displayHeap(minHeapOrList MH) {
	int i;
	for (i = 0; i <= MH.lastNdx; i++) {
		printf("(%d, %d, %d) ", MH.edges[i].u, MH.edges[i].v, MH.edges[i].weight);
	}
}

MST Kruskals(LabelAdjMat A) {
	MST K;
	initMST(&K);
	minHeapOrList MH = createMinHeap(A);
	char components[] = {'A', 'B', 'C', 'D', 'E'};
	int edgeCount;
	for (edgeCount = 1; edgeCount < MAX; ) {
		edgetype min = deleteMinHeap(&MH);
		// if components are different, add minimum edge to MST, add cost, and update each component to the smaller component
		if (components[min.u] != components[min.v]) {
			insert(&(K.eList), min);
			K.cost += min.weight;
			edgeCount++;
			char com1, com2;
			if (components[min.u] < components[min.v]) {
				com1 = components[min.u];
				com2 = components[min.v];
			} else {
				com1 = components[min.v];
				com2 = components[min.u];
			}
			int i;
			for (i = 0; i < MAX; i++) {
				if (components[i] == com2) components[i] = com1;
			}
		}
	}
	return K;
}

MST Prims(LabelAdjMat A, vertex startV) {
	MST P;
	initMST(&P);
	minHeapOrList MH = createMinHeap(A);
	// bit vector that represent visited (1) and unvisited (0) vertex
	int V[MAX] = {0, 0, 0, 0, 0}, edgeCount;
	V[startV] = 1;
	for (edgeCount = 1; edgeCount < MAX; ) {
		edgetype min = deleteMinHeap(&MH);
		// if only one ot the two vertex is visited, add minimum edge to MST, add cost, and mark the vertex visited
		if ((V[min.u] == 0 && V[min.v] == 1) || (V[min.u] == 1 && V[min.v] == 0)) {
			insert(&(P.eList), min);
			P.cost += min.weight;
			edgeCount++;
			V[min.u] = V[min.v] = 1;
		}
	}
	return P;
}
