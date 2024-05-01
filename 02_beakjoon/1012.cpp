#include <bits/stdc++.h>
using namespace std;

int t;
int m, n, k;
int boards[51][51];
int visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

        if (!visited[nx][ny] && boards[nx][ny])
            dfs(nx, ny);
    }

    return ;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 테스트 케이스 개수 입력
    cin >> t;

    while(t--)
    {
        // boards, visited 초기화
        fill(&boards[0][0], &boards[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        // 가로, 세로, 배추가 심어진 위치의 개수 입력
        cin >> m >> n >> k;

        // 배추 좌표 입력
        int x, y;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            boards[x][y] = 1;
        }

        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (boards[i][j] == 1 && visited[i][j] == 0)
                {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }
}