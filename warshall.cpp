#include <iostream>
using namespace std;

#define V 4 // Number of vertices

void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void warshall(int graph[V][V]) {
    int transitiveClosure[V][V];

    // Initialize transitive closure matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            transitiveClosure[i][j] = graph[i][j];
        }
    }

    // Update transitive closure matrix
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    cout << "Transitive Closure of the graph:\n";
    printMatrix(transitiveClosure);
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    warshall(graph);
    return 0;
}
