#include <iostream>
#include <climits>
using namespace std;

#define V 5 // Number of vertices

// Function to find the vertex with the minimum distance
int findMinDistance(int dist[], bool visited[]) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Distance array to store the shortest distance from the source
    bool visited[V]; // Visited array to mark visited vertices

    // Initialize distances and visited
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // Initially, all distances are infinity
        visited[i] = false; // No vertex is visited yet
    }

    dist[src] = 0; // Distance to the source is 0

    // Process all vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum distance
        int u = findMinDistance(dist, visited);

        // Mark the vertex as visited
        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // 1. There is an edge from u to v
            // 2. v is not visited
            // 3. New distance is smaller than the current distance
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the distances
    cout << "Vertex\tShortest Distance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 20},
        {10, 0, 10, 0, 0},
        {0, 10, 0, 30, 0},
        {0, 0, 30, 0, 0},
        {20, 0, 0, 0, 0}
    };

    int sourceVertex = 0; // Source vertex
    dijkstra(graph, sourceVertex);

    return 0;
}
