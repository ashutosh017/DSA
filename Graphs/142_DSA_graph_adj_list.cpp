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

void addEdge(vi vec[], int u, int v){
    vec[u].pb(v);
    vec[v].pb(u);
}

void printGraph(vi vec[], int v){
    rep(i,v){
        for(auto x: vec[i])cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    int v=5; //--> no. of vertices
    vi adjList[v];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    printGraph(adjList, v);
    
    return 0;
}