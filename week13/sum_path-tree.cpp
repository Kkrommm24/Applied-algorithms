#include <bits/stdc++.h>
using namespace std;

#define N 10001
struct Arc
{
    int node;
    int w;
    Arc(int _node, int _w)
    {
        node = _node;
        w = _w;
    }
};
vector<Arc> A[N];
int n;
int d[N], f[N], Num[N], p[N];

void input()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        A[u].push_back(Arc(v, w));
        A[v].push_back(Arc(u, w));
    }
}


void init()
{
    for (int v = 1; v <= n; v++)
    {
        d[v] = -1;
        p[v] = 0;
    }
}

void DFS1(int u)
{
    for (Arc a : A[u])
    {
        int v = a.node;
        int w = a.w;
        if (p[v] == 0)
        {
            p[v] = u;
            DFS1(v);
            d[u] = d[u] + d[v] + Num[v] * w;
            Num[u] = Num[u] + Num[v];
        }
    }
}

void Phase1()
{
    for (int v = 1; v <= n; v++)
    {
        d[v] = 0;
        p[v] = 0;
        Num[v] = 1;
    }
    p[1] = 1; // select node 1 as the root
    DFS1(1);
}

void DFS2(int u)
{
    for (Arc a : A[u])
    {
        int v = a.node;
        int w = a.w;
        if (p[v] == 0)
        {
            int F = f[u] - (d[v] + Num[v] * w);
            f[v] = F + w * (n - Num[v]) + d[v];
            p[v] = u;
            DFS2(v);
        }
    }
}

void Phase2()
{
    for (int v = 1; v <= n; v++)
    {
        p[v] = 0;
    }
    f[1] = d[1];
    p[1] = 1; // 1 is the root
    DFS2(1);
    int res = f[1];
    for (int v = 2; v <= n; v++)
        res = max(res, f[v]);
    cout << res;
}

int main()
{
    input();
    Phase1();
    Phase2();
    return 0;
}
