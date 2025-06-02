#include <stdio.h>
#include <conio.h>  // For getch() in Turbo C
#include <stdlib.h>

#define V 5
#define bool int
#define true 1
#define false 0

void printSolution(int path[]);

// A utility function to check if the vertex v can be added at index 'pos'
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive utility function to solve Hamiltonian Cycle problem
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Solves the Hamiltonian Cycle problem using Backtracking
bool hamCycle(bool graph[V][V]) {
    int path[V];
    int i;

    for (i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        printf("\nSolution does not exist\n");
        return false;
    }

    printSolution(path);
    return true;
}

// A utility function to print solution
void printSolution(int path[]) {
    int i;
    printf("Solution Exists: Following is one Hamiltonian Cycle:\n");
    for (i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d \n", path[0]); // To show complete cycle
}

// Driver code
int main() {
    bool graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamCycle(graph1);

    bool graph2[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    hamCycle(graph2);

    getch();  // Pause for Turbo C++
    return 0;
}
