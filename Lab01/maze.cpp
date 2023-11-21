#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MAX_M 1000

long n, m, r, c;
long maze[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

struct Point
{
    long x, y, steps;
};

bool isValid(long x, long y)
{
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0;
}

void input()
{
    cin >> n >> m >> r >> c;
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
}

long bfs()
{
    long dx[] = {0, 0, -1, 1};
    long dy[] = {-1, 1, 0, 0};

    queue<Point> q;
    q.push({r - 1, c - 1, 1});
    visited[r - 1][c - 1] = true;
    while (!q.empty())
    {
        Point current = q.front();
        q.pop();

        if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1)
        {
            return current.steps;
        }

        for (long i = 0; i < 4; i++)
        {
            long newX = current.x + dx[i];
            long newY = current.y + dy[i];

            if (isValid(newX, newY) && !visited[newX][newY])
            {
                q.push({newX, newY, current.steps + 1});
                visited[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main()
{
    input();
    long result = bfs();
    cout << result << endl;
    return 0;
}