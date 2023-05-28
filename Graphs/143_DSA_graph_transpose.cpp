#include <bits/stdc++.h>
// #include<iostream>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define ford(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define rep(i, n) forn(i, 0, n - 1)
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

void addEdge(vi adj[], int u, int v)
{
    adj[u].pb(v);
}
void printGraph(vi adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "-->";
        // rep(j, adj[i].size()){   //-->not working maybe because of macro problem
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeGraph(vi adj[], vi trans[], int v)
{
    // rep(i,v)rep(j,adj[i].size())addEdge(trans, adj[i][j], i);    //-->not working maybe because of macro problem
    // rep(i,v)forn(j,0,adj[i].size()-1)addEdge(trans, adj[i][j], i);   //-->not working maybe because of macro problem
    // rep(i,v)for(int j = 0;j<adj[i].size();j++)addEdge(trans, adj[i][j], i);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
            addEdge(trans, adj[i][j], i);
}
int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
    printGraph(adj, v);
    cout << endl;
    vi transpose[v];
    transposeGraph(adj, transpose, v);
    printGraph(transpose, v);
    return 0;
}