#include <bits/stdc++.h> 
using namespace std;
#define N 100001

long n, m;
vector<int> A[N];
bool visited[N];
long nbCC;
long cc[N];

void DFS(long u) { // DFS starts from node u
    cc[u] = nbCC;
    visited[u] = true;
    for (long i = 0; i < A[u].size(); i++) {
        long v = A[u][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}

void DFSWithStack(int u){
    stack<int> S;
    S.push(u); visited[u] = true; cc[u] = nbCC;
    while(!S.empty()){
        int v = S.top(); S.pop();
        for(int i = 0; i < A[v].size(); i++){
            int x = A[v][i];
            if(!visited[x]){
                S.push(x); visited[x] = true; cc[x] = nbCC;
            }
        }
    }
}

void findConnectedComponents() {
    for (long v = 1; v <= n; v++) {
        visited[v] = false;
    }
    nbCC = 0;
    for (long u = 1; u <= n; u++) {
        if (!visited[u]) {
            nbCC = nbCC + 1;
            // DFS(u);
            DFSWithStack(u);
        }
    }
    // cout << nbCC << endl;
    for (int c = 1; c <= nbCC; c++) {
        // cout << c;
        for (int v = 1; v <= n; v++) {
            if (cc[v] == c) {
                cout << v << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for (long i = 1; i <= m; i++) {
        long u, v; cin >> u >> v;
        A[u].push_back(v); // add v at the list A[u]
        A[v].push_back(u); // add u at the list A[v]
    }
    findConnectedComponents();
    return 0;
}
