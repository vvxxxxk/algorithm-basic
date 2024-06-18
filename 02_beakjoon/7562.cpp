#include <bits/stdc++.h>
using namespace std;

int t, l;
int sx, sy, tx, ty;
int boards[304][304];
int visited[304][304];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int cnt;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (q.size())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 이동할 좌표가 범위를 벗어난 경우, continue
            if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                continue;

            // 이동할 좌표에 이미 방문한 경우, continue
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx, ny});

            if (nx == tx && ny == ty)
                return;
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 테스트 케이스 개수 입력
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // visited 배열 초기화
        fill(&visited[0][0], &visited[0][0] + 304*304, 0);

        cin >> l;           // 길이 입력
        cin >> sx >> sy;    // 현재 위치 x, y 좌표 입력
        cin >> tx >> ty;    // 타겟 위치 x, y 좌표 입력

        bfs(sx, sy);

        cout << visited[tx][ty] - 1 << "\n";    // 최소 이동 횟수 출력
    }
}