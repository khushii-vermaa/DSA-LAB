#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void displayList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto v : adjList[i]) cout << v << " ";
            cout << endl;
        }
    }

    int degree(int v) {
        return adjList[v].size();
    }

    int countEdges() {
        int edges = 0;
        for (int i = 0; i < V; i++)
            edges += adjList[i].size();
        return edges / 2;
    }

    void adjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (auto x : adjList[v]) cout << x << " ";
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.displayMatrix();
    g.displayList();

    cout << "\nDegree of vertex 3 = " << g.degree(3) << endl;
    g.adjacentVertices(3);
    cout << "Total edges = " << g.countEdges() << endl;

    return 0;
}
