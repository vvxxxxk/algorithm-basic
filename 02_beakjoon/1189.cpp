#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char boards[10][10];
int visited[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ret;

void go(int x, int y, int dist)
{

    if (x == 0 && y == c-1 && dist == k)
    {
        ret++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
        
        if (visited[nx][ny])
            continue;
        
        if (boards[nx][ny] == 'T')
            continue;
        
        visited[nx][ny] = 1;
        go(nx, ny, dist+1);
        visited[nx][ny] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> boards[i][j];
    }

    visited[r-1][0] = 1;
    go(r-1, 0, 1);
    cout << ret << "\n";
}