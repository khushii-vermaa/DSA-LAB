#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS_Stack(vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false);
    stack<int> st;

    st.push(start);

    cout << "DFS Traversal (using stack): ";

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        // Push all adjacent nodes of v (in reverse order for correct order)
        for (int i = adj[v].size() - 1; i >= 0; i--) {
            int u = adj[v][i];
            if (!visited[u]) {
                st.push(u);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    DFS_Stack(graph, 0);
    return 0;
}
