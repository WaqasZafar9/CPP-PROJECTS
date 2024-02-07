#include <iostream>
#include <climits>

using namespace std;

#define V 5
#define E 8

struct Edge {
    int src, dest, weight;
};

void bellmanFord(Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle. Bellman-Ford cannot solve this." << endl;
            return;
        }
    }

    cout << "Shortest distances from source " << src << " to all other vertices:\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << ": " << dist[i] << endl;
}

int main() {
    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;
    bellmanFord(edges, source);

    return 0;
}
