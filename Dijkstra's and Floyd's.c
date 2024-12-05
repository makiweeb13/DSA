#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INFINITY 999

typedef int Vertex;

typedef int LabelAdjMat[MAX][MAX];

typedef struct {
	int distance[MAX];
	int prev[MAX];
	int distAll[MAX][MAX];
} ShortestPath;

typedef struct {
	int visited[MAX];
	int count;
} Visited;

ShortestPath Dijkstra(LabelAdjMat M, Vertex start);
void initShortestPath(ShortestPath *SP);
void initBitVector(Visited *V);
void displayDijkstra(ShortestPath SP);
ShortestPath Floyd(LabelAdjMat M);
void displayFloyd(LabelAdjMat M);

int main() {
	LabelAdjMat M = {
		{0, 10, INFINITY, 30, 100},
		{INFINITY, 0, 50, INFINITY, INFINITY},
		{20, INFINITY, 0, INFINITY, 10},
		{INFINITY, INFINITY, 20, 0, 60},
		{INFINITY, INFINITY, INFINITY, INFINITY, 0}
	};
	ShortestPath SP = Dijkstra(M, 0);
	displayDijkstra(SP);
	ShortestPath ASP = Floyd(M);
	displayFloyd(ASP.distAll);
	return 0;
}

void initShortestPath(ShortestPath *SP) {
	int i;
	for (i = 0; i < MAX; i++) {
		SP->distance[i] = INFINITY;
		SP->prev[i] = INFINITY;
	}
}

void initBitVector(Visited *V) {
	int i;
	for (i = 0; i < MAX; i++) {
		V->visited[i] = 0;
	}	
	V->count = MAX-1;
}

ShortestPath Dijkstra(LabelAdjMat M, Vertex start) {
	// initialize shortest paths
	ShortestPath SP;
	initShortestPath(&SP);
	SP.distance[start] = 0;
	
	// bit vector to represent visited (1) and unvisited(0) vertex
	Visited V;
	initBitVector(&V);
	
	// Dijkstra's logic
	Vertex curr = start, smallest;
	
	// while there are unvisited vertices
	while (V.count > 0) {
		// visit current vertex
		V.visited[curr] = 1;
		V.count--;
		
		// tracks unvisited vertex with smallest path		
		smallest = INFINITY;
		int i;
		for (i = 0; i < MAX; i++) {
			// for every unvisited neighbours, calculate shortest distance and update shortest path if necessary
			if ((M[curr][i] != INFINITY && M[curr][i] != 0) && V.visited[i] == 0) {
				int distance = SP.distance[curr] + M[curr][i];
				if (SP.distance[i] > distance) {
					SP.distance[i] = distance;
					SP.prev[i] = curr;
				}
				smallest = smallest > M[curr][i] ? i : smallest;
			}
		}
		// set the next vertex to the current smallest
		curr = smallest;
	}
	return SP;
}

void displayDijkstra(ShortestPath SP) {
	printf("Dijkstra's Algorithm: \n\tdistance from\n");
	int i;
	for (i = 0; i < MAX; i++) {
		printf("%d\t%d\t %d\n", i, SP.distance[i], SP.prev[i]);
	}
}

ShortestPath Floyd(LabelAdjMat M) {
	ShortestPath ASP;
	int i, j, k;
	// copy input matrix to new matrix
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			ASP.distAll[i][j] = M[i][j];
		}
	}
	// set diagonals to 0
	for (i = 0; i < MAX; i++) {
		ASP.distAll[i][i] = 0;
	}
	// Floyd's logic
	for (k = 0; k < MAX; k++) {
		for (i = 0; i < MAX; i++) {
			for (j = 0; j < MAX; j++) {
				if (ASP.distAll[i][j] > ASP.distAll[i][k] + ASP.distAll[k][j]) {
					ASP.distAll[i][j] = ASP.distAll[i][k] + ASP.distAll[k][j];
				}
			}
		}
	}
	return ASP;
}

void displayFloyd(LabelAdjMat M) {
	printf("Floyd's Algorithm:\n");
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf("[%d]", M[i][j]);
		}
		printf("\n");
	}
}
