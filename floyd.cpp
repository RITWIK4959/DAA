#include <iostream>
using namespace std;

#define V 4 // Number of vertices
#define INF 99999 // Representation of infinity

void floydWarshall(int graph[V][V]) {
    // Distance matrix
    int dist[V][V];

    // Copy input graph to distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update distances using Floyd's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, INF, 15},
        {50, 0, 15, INF},
        {INF, INF, 0, 5},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}
