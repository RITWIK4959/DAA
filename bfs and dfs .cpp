#include <iostream>
#include <cstring>
using namespace std;

// Graph represented as an adjacency matrix
const int MAX_NODES = 5;
char nodes[MAX_NODES] = {'A', 'B', 'C', 'D', 'E'}; // Node names
int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 0, 0, 1}, // Connections from A
    {1, 0, 1, 1, 0}, // Connections from B
    {0, 1, 0, 0, 0}, // Connections from C
    {0, 1, 0, 0, 1}, // Connections from D
    {1, 0, 0, 1, 0}  // Connections from E
};

// Find the index of a node
int getNodeIndex(char node) {
    for (int i = 0; i < MAX_NODES; ++i) {
        if (nodes[i] == node)
            return i;
    }
    return -1;
}

// BFS Implementation
void bfs(char startNode) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES], front = 0, rear = 0;

    int startIndex = getNodeIndex(startNode);
    if (startIndex == -1) {
        cout << "Node not found in graph.\n";
        return;
    }

    // Enqueue the starting node
    queue[rear++] = startIndex;
    visited[startIndex] = true;

    cout << "BFS Traversal starting from " << startNode << ": ";
    while (front < rear) {
        int currentNode = queue[front++];
        cout << nodes[currentNode] << " ";

        // Visit all neighbors
        for (int i = 0; i < MAX_NODES; ++i) {
            if (graph[currentNode][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// DFS Implementation
void dfsUtil(int currentNode, bool visited[]) {
    visited[currentNode] = true;
    cout << nodes[currentNode] << " ";

    // Visit all neighbors
    for (int i = 0; i < MAX_NODES; ++i) {
        if (graph[currentNode][i] && !visited[i]) {
            dfsUtil(i, visited);
        }
    }
}

void dfs(char startNode) {
    bool visited[MAX_NODES] = {false};
    int startIndex = getNodeIndex(startNode);

    if (startIndex == -1) {
        cout << "Node not found in graph.\n";
        return;
    }

    cout << "DFS Traversal starting from " << startNode << ": ";
    dfsUtil(startIndex, visited);
    cout << endl;
}

int main() {
    char startNode = 'B';

    cout << "Graph traversal using BFS and DFS:\n";
    bfs(startNode);
    dfs(startNode);

    return 0;
}
