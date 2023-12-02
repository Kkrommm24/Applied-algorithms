#include <bits/stdc++.h>
using namespace std;
#define N 100001
/* test case:
8 12
1 2
1 8
2 3
3 6
4 3
5 3
5 4
6 5
7 1
7 2
7 6
8 7
*/

int n, m;
vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int num[N], low[N];
int t;
int nbSCC;

bool inStack[N];
stack<int> S;

void input()
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v); // add v at the list A[u], do thi co huong nen chi la 1 chieu
    }
}

void DFS(int u)
{
    t = t + 1;
    num[u] = t;
    low[u] = t;
    S.push(u);
    inStack[u] = true;
    for (int i = 0; i < A[u].size(); i++)
    {
        int v = A[u][i];
        if (num[v] > 0){
            if (inStack[v]){
                low[u] = min(low[u], num[v]);
            }
        }else{
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        
    }
    if (low[u] == num[u])
    { // discovered a trongly connected component
        // cout << "scc: ";
        nbSCC += 1;
        // while (!S.empty()){
        //     int x = S.top();
        //     S.pop();
        //     cout << x << " ";
        //     if (x == u)
        //         break;
        // }
        // cout << endl;
    }
}

int main()
{
    input();
    nbSCC = 0;
    for (int v = 1; v <= n; v++)
    {
        num[v] = -1;
        low[v] = -1;
        inStack[v] = false;
    }
    t = 0;
    for (int v = 1; v <= n; v++)
    {
        if (num[v] < 0)
            DFS(v);
    }
    cout << nbSCC;
    return 0;
}