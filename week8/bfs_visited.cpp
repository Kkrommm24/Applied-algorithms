#include <bits/stdc++.h>
using namespace std;
#define N 100001

int n, m;
vector<int> A[N];
bool visited[N];
int level[N]; // shortest distance from begin to v

void BFS(int u)
{
    queue<int> Q;
    Q.push(u);
    level[u] = 0;
    cout << u << " ";
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < A[v].size(); i++)
        {
            int x = A[v][i];
            if (level[x] == -1)
            { // not visited
                Q.push(x);
                level[x] = level[v] + 1;
                cout << x << " ";
            }
        }
    }
}
void BFS()
{
    for (int v = 1; v <= n; v++)
        level[v] = -1;
    for (int v = 1; v <= n; v++)
    {
        if (level[v] == -1)
        {
            BFS(v);
        }
    }
}
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for (int v = 1; v <= n; v++)
    {
        sort(A[v].begin(), A[v].end());
    }
}

void printGraph()
{
    for (int v = 1; v <= n; v++)
    {
        cout << "A[" << v << "]: ";
        for (int i = 0; i < A[v].size(); i++)
        {
            int x = A[v][i];
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    input();
    BFS();
    // printGraph();
    return 0;
}