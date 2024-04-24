#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>
#include <omp.h>
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

    vector<T> DFS(T start) {
        vector<T> DFSTraversal;
        stack<T> q;

        // Mark all vertices as not visited
        for (auto& pair : adj) {
            visited[pair.first] = false;
        }

        // Enqueue the start vertex and mark it as visited
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            T current = q.top();
            q.pop();
            DFSTraversal.push_back(current);

            // Visit all adjacent vertices of the current vertex
        
            for (T neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return DFSTraversal;
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS Traversal starting dm vertex " << startVertex << ":" << endl;
    auto start = chrono::steady_clock::now();
    vector<int> DFSResult = g.DFS(startVertex);
    auto end = chrono::steady_clock::now();
    for (int node : DFSResult) {
        cout << node << " ";
    }
    cout << endl;

    cout<<"time :"<<chrono::duration_cast<chrono::seconds>(end-start).count();

    return 0;
}
