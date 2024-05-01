#include <bits/stdc++.h>
using namespace std;

int n;
int area_cnt;
int max_area_cnt = -1;
int boards[100][100];
int visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (boards[nx][ny] != 0 && visited[nx][ny] == 0)
            dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> boards[i][j];
        }
    }

    for (int k = 0; k <= 100; k++)
    {
        // visited 초기화
        fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (boards[i][j] <= k)
                    boards[i][j] = 0;
            }
        }

        area_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0 && boards[i][j] != 0)
                {
                    dfs(i, j);
                    area_cnt++;
                }
            }
        }

        max_area_cnt = max(max_area_cnt, area_cnt);
    }

    cout << max_area_cnt << "\n";
}