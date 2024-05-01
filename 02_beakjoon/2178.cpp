#include <bits/stdc++.h>
using namespace std;

int n, m;
int boards[104][104];
int visited[104][104];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});

    while (q.size())
    {
        pair<int, int> cur_p = q.front();
        int cx = cur_p.first;
        int cy = cur_p.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (boards[nx][ny] == 0 || visited[nx][ny])
                continue;
            
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            boards[i][j] = s[j] - '0';
    }

    bfs(0, 0);

    cout << visited[n-1][m-1] << "\n";

}