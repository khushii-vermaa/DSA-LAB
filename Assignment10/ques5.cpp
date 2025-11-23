#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int>& key, vector<bool>& mstSet, int n) {
    int minVal = INT_MAX, index;
    for (int i = 0; i < n; i++)
        if (!mstSet[i] && key[i] < minVal)
            minVal = key[i], index = i;
    return index;
}

void Prims(vector<vector<int>>& graph, int n) {
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mstSet(n, false);

    key[0] = 0;

    for (int i = 0; i < n-1; i++) {
        int u = findMin(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Prim’s MST:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " -- " << i << " = " << graph[i][parent[i]] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    Prims(graph, 5);
}
