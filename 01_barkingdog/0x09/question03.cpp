/*
 *  https://www.acmicpc.net/problem/7576
 */
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n, m;
    cin >> m >> n;

    queue<pair<int, int>> q;
    int board[n][m];
    int dist[n][m];
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, 0);
        

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
                q.push({i, j});
            if (board[i][j] == 0)
                dist[i][j] = -1;
        }
    }

    while (!q.empty())
    {
        pair<int, int> point = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = point.X + dx[i];
            int y = point.Y + dy[i];

            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (dist[x][y] >= 0)
                continue;
            dist[x][y] = dist[point.X][point.Y] + 1;
            q.push({x, y});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << "\n";
}