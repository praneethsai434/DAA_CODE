#include <stdio.h>
#include <limits.h>

#define V 5
#define INF 99999

int minDistance(int dist[], int visited[]) {
    int min = INF, min_idx = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Dijkstra (from source %d):\n", src);
    for (int i = 0; i < V; i++) printf("Vertex %d -> Distance %d\n", i, dist[i]);
}

void bellmanFord(int edges[][3], int e, int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    printf("\nBellman-Ford (from source %d):\n", src);
    for (int i = 0; i < V; i++) printf("Vertex %d -> Distance %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 2, 0, 0},
        {0, 0, 1, 5, 0},
        {0, 0, 0, 8, 10},
        {0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0}
    };

    int edges[][3] = {
        {0, 1, 4}, {0, 2, 2}, {1, 2, 1}, {1, 3, 5},
        {2, 3, 8}, {2, 4, 10}, {3, 4, 2}
    };
    int e = sizeof(edges) / sizeof(edges[0]);

    dijkstra(graph, 0);
    bellmanFord(edges, e, 0);
    return 0;
}
