/*
 *  https://www.acmicpc.net/problem/2178
 */
#include <iostream>
#include <queue>
using namespace std;

// pair에서 first, second를 줄여서 쓰기 위해서 사용
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n: 행, m: 열
    int n, m;
    cin >> n >> m;
    // 미로
    string board[n];
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // dist 배열 선언 및 초기화
    int dist[n][m];
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

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
            if (dist[x][y] > 0 || board[x][y] != '1')
                continue;
            
            dist[x][y] = dist[point.X][point.Y] + 1;
            q.push({x, y});
        }
    }

    cout << dist[n-1][m-1] + 1 << "\n";
}