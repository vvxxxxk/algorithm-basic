#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int ret;
int cnt;
vector<int> cnts;
int boards[104][104];
int visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (visited[nx][ny] == 0 && boards[nx][ny] == 0)
        {
            dfs(nx, ny);
            cnt++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= y1 && i < y2 && j >= x1 && j < x2)
                    boards[i][j] = 1;                
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (boards[i][j] == 0 && visited[i][j] == 0)
            {
                cnt = 1;
                dfs(i, j);
                ret++;
                cnts.push_back(cnt);
            }
        }
    }
    
    cout << ret << "\n";
    sort(cnts.begin(), cnts.end());
    for (int cnt : cnts)
        cout << cnt << " ";
    cout << "\n";
}