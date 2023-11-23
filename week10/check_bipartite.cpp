#include <bits/stdc++.h>
using namespace std;
#define N 100001

vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n, m;
int d[N]; // level of  node v

void input()
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v); // add v at the list A[u]
        A[v].push_back(u); // add u at the list A[v]
    }
}

bool BFS(int u)
{
    // return true if no violations of bipartite property
    // return false if the given graph is not bipartite
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < A[v].size(); i++)
        {
            int x = A[v][i];
            if (d[x] >= 0)
            { // x has been visited
                if ((d[x] + d[v]) % 2 == 0)
                    return false;
            }
            else
            {
                Q.push(x);
                d[x] = d[v] + 1;
            }
        }
    }
    return true;
}

int main()
{
    input();
    for (int v = 1; v <= n; v++)
        d[v] = -1;
    int bipartite = 1;
    for (int u = 1; u <= n; u++)
        if (d[u] < 0)
        {
            bool ok = BFS(u);
            if (!ok)
                bipartite = 0; break;
        }
    cout << bipartite;
    return 0;
}