#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    parent[b] = a;
}

void Kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "Kruskal MST:\n";
    int cost = 0;

    for (auto e : edges) {
        if (findParent(e.src, parent) != findParent(e.dest, parent)) {
            cout << e.src << " -- " << e.dest << " = " << e.weight << endl;
            cost += e.weight;
            unionSet(e.src, e.dest, parent);
        }
    }
    cout << "Total Cost = " << cost << endl;
}

int main() {
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    Kruskal(edges, 4);
}
