#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> junan, choco;
int boards[304][304];
int visited[304][304];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int cx, cy;
bool flag = false;

void bfs(int x, int y)
{
    visited[x][y] = 1;
    q1.push({x, y});

    while (q1.size() || q2.size())
    {
        // q1이 비었을 때
        if (q1.size() == 0)
        {
            int q_size = q2.size();
            for (int i = 0; i < q_size; i++)
            {
                int fx = q2.front().first;
                int fy = q2.front().second;
                q2.pop();

                if (visited[fx][fy])
                    continue;

                // 친구 -> 빈칸
                boards[fx][fy] = 0;
                // 방문처리
                visited[fx][fy] = visited[cx][cy] + 1;

                // q1에 삽입
                q1.push({fx, fy});
            }
        }
        cx = q1.front().first;
        cy = q1.front().second;
        q1.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if (visited[nx][ny])
                continue;
            
            // (nx,ny)가 빈 공간일 때
            if (boards[nx][ny] == 0)
            {
                q1.push({nx, ny});
                visited[nx][ny] = visited[cx][cy];
            }

            // (nx,ny)가 친구일 때
            if (boards[nx][ny] == 1)
            {
                q2.push({nx, ny});
            }

            // (nx,ny)가 범인일 때
            if (boards[nx][ny] == 4)
            {
                flag = true;
                visited[nx][ny] = visited[cx][cy];
                break;
            }
        }
        if (flag)
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> junan.first >> junan.second >> choco.first >> choco.second;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < input.size(); j++)
        {
            if (input[j] == '0')
                boards[i][j] = 0;
            else if (input[j] == '1')
                boards[i][j] = 1;
            else if (input[j] == '*')
                boards[i][j] = 3;
            else if (input[j] == '#')
                boards[i][j] = 4;
        }
    }

    bfs(junan.first-1, junan.second-1);
    cout << visited[choco.first-1][choco.second-1] << "\n";
}