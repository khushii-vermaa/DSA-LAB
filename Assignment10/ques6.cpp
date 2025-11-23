#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDist(vector<int> dist, vector<bool> visited, int n) {
    int minVal = INT_MAX, index;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < minVal)
            minVal = dist[i], index = i;
    return index;
}

void Dijkstra(vector<vector<int>> graph, int src, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n-1; i++) {
        int u = minDist(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dist[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    Dijkstra(graph, 0, 9);
}
