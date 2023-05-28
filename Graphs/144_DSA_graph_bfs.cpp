#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define rep(i, n) forn(i, 0, n - 1)
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int v, int w); 
    void BFS(int s);
    void BFS2(); 
};

// Undirected graph using adjacency list
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// BFS for connected graph only
void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[s] = true;
    queue.pb(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.pb(adjacent);
            }
        }
    }
}

// For disconnected graph
void Graph::BFS2()
{
    // vector<bool> visited;
    // visited.resize(V, false);

    // for (int i = 0; i < V; i++)
    // {
    //     if (!visited[i])
    //     {
    //         list<int> queue;
    //         visited[i] = true;
    //         queue.pb(i);

    //         while (!queue.empty())
    //         {
    //             int s = queue.front();
    //             cout << s << " ";
    //             queue.pop_front();
    //             for (auto adjacent : adj[s])
    //             {
    //                 if (!visited[adjacent])
    //                 {
    //                     visited[adjacent] = true;
    //                     queue.pb(adjacent);
    //                 }
    //             }
    //         }
    //     }
    // }


}

/* Pitfalls I observe about this bfs function
    -> You cannot be able to add vertex of value greater than no. of vertexes
    -> bfs for undirected graph prints all the values from 0 to V(no. of vertexes) even though they are not present in the graph.
 */

int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    // g.BFS(1);
    // cout << endl;


    g.BFS2();
    cout << endl;
    // vi v= g.bfsOfGraph();
    // for (auto &&i : v)
    // {
    //     cout<<i<<" ";
    // }    
    // cout << endl;
    return 0;
}