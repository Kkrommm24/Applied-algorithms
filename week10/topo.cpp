#include <bits/stdc++.h>
using namespace std;
#define N 100001

vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n, m;
int d[N]; // the in-degree of node V

int main()
{
    cin >> n >> m;
    for (int v = 1; v <= n; v++)
        d[v] = 0;
    for (int k = 1; k <= m; k++)
    {
        int u, v;
        cin >> u >> v; // read an arc (u,v)
        d[v] = d[v] + 1;
        A[u].push_back(v);
    }
    queue<int> Q;
    for (int v = 1; v <= n; v++)
    {
        if (d[v] == 0)
            Q.push(v);
    }
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        cout << v << " ";
        for (int i = 0; i < A[v].size(); i++)
        {
            int x = A[v][i];
            d[x] = d[x] - 1;
            if (d[x] == 0)
            {
                Q.push(x);
            }
        }
    }
    return 0;
}