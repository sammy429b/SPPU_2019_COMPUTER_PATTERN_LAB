#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <chrono>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, set<T>> adj;
    unordered_map<T, bool> visited;

    void addEdge(T u, T v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    vector<T> BFS(T start) {
        vector<T> bfsTraversal;
        queue<T> q;

        // Mark all vertices as not visited
        for (auto& pair : adj) {
            visited[pair.first] = false;
        }

        // Enqueue the start vertex and mark it as visited
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            T current = q.front();
            q.pop();
            bfsTraversal.push_back(current);

            // Visit all adjacent vertices of the current vertex
            for (T neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfsTraversal;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph<int> g;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Adjacency List representation of the graph:" << endl;
    g.printAdjList();

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << ":" << endl;
    auto start = chrono::steady_clock::now();
    vector<int> bfsResult = g.BFS(startVertex);
    auto end = chrono::steady_clock::now();
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;
     cout<<"time :"<<chrono::duration_cast<chrono::seconds>(end-start).count();

    return 0;
}
