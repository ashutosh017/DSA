#include <bits/stdc++.h>
//#include<iostream>
using namespace std;
#define ll long long
#define forn(i, a, b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define rep(i, n) forn(i, 0, n-1)
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(),x.end()

// Graph representation using adjacency list
class Graph{
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w);
    // Recursive functions
    void DFS(int v);
    void DFS2(); // --> For disconnected graph
};

void Graph::addEdge(int v, int w){
    adj[v].pb(w);
    adj[w].pb(v);
}

// DFS for undirected connected graph
void Graph::DFS(int v){
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i])DFS(*i);
    }
}
// DFS for undirected disconnected graph
void Graph::DFS2(){
    for(auto i:adj){
        if(!visited[i.first])DFS(i.first);
    }
}
int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(5,3);
    g.addEdge(6,7);
    // g.DFS(1);cout<<endl;
    g.DFS2();cout<<endl;
    
    return 0;
}