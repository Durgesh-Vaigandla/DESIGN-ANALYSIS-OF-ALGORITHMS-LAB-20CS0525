#include <stdio.h>
#include <stdlib.h>

#define V 5
#define TRUE 1
#define FALSE 0

void printSolution(int path[]);

// A utility function to check if the vertex v can be added at index 'pos'
    if (graph[path[pos - 1]][v] == 0)
        return FALSE;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return FALSE;

    return TRUE;
}

// Recursive utility function to solve Hamiltonian Cycle problem
int hamCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return TRUE;
        else
            return FALSE;
    }
    }
    int v;
    for (v = 1; v < V; v++) {
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            if (hamCycleUtil(graph, path, pos + 1))
                return TRUE;

            // Backtrack
            path[pos] = -1;
        }
    }

    return FALSE;
}

// Solves the Hamiltonian Cycle problem using Backtracking
int hamCycle(int graph[V][V]) {
// Solves the Hamiltonian Cycle problem using Backtracking
    int i;
    for (i = 0; i < V; i++)
    int *path = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        path[i] = -1;
    if (!hamCycleUtil(graph, path, 1)) {
        printf("\nSolution does not exist\n");
        free(path);
        return FALSE;
    }

    printSolution(path);
    free(path);
    return TRUE;
    printSolution(path);
    free(path);
    return true;
}

    int i;
    for (i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf("Solution Exists: Following is one Hamiltonian Cycle:\n");
    for (int i = 0; i < V; i++)
// Driver code
int main() {
    int graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamCycle(graph1);

    int graph2[V][V] = {

    hamCycle(graph1);

    bool graph2[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    hamCycle(graph2);

    return 0;
}   