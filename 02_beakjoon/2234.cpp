#include <bits/stdc++.h>
using namespace std;

int n, m, room_size;
int boards[51][51];
int visited[51][51];
int dx[4] = {0, -1, 0, 1};  // 서, 북, 동, 남
int dy[4] = {-1, 0, 1, 0};  // 서, 북, 동, 남

int ret1;   // 방 개수
int ret2;   // 가장 넓은 방의 크기
int ret3;   // 벽 1개 제거 후 얻을 수 있는 가장 넓은 방의 크기

void dfs(int x, int y)
{
    // 방문
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        // 벽에 의해 이동할 수 없을 경우, continue
        if (boards[x][y] & (1 << i))
            continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 성을 벗어난 경우, continue
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        
        // 이미 방문한 경우, continue
        if (visited[nx][ny])
            continue;
        
        // 방문
        visited[nx][ny] = 1;
        room_size++;

        dfs(nx, ny);
    }
}

void remove_dfs(int x, int y)
{
    // 방문
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        // 벽에 의해 이동할 수 없을 경우, continue
        if (boards[x][y] & (1 << i))
            continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 성을 벗어난 경우, continue
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        
        // 이미 방문한 경우, continue
        if (visited[nx][ny])
            continue;
        
        // 방문
        visited[nx][ny] = 1;
        room_size++;

        remove_dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> boards[i][j];
    }

    // dfs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 아직 방문하지 않는 지점을 시작포인트로 설정하고 dfs 수행
            if (visited[i][j] == 0)
            {
                room_size = 1;
                dfs(i, j);
                ret1++;
                ret2 = max(ret2, room_size);
            }
                
        }
    }

    // 벽 1개 제거후 얻을 수 있는 가장 넓은 방의 크기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 모든 좌표에 벽을 한 개 제거 후 dfs
            for (int k = 0; k < 4; k++)
            {
                fill(&visited[0][0], &visited[0][0] + 51*51, 0);
                int origin = boards[i][j];
                boards[i][j] = boards[i][j] & ~(1 << k);
                room_size = 1;
                remove_dfs(i, j);
                boards[i][j] = origin;
                ret3 = max(ret3, room_size);
            }
        }
    }
    
    cout << ret1 << "\n";
    cout << ret2 << "\n";
    cout << ret3 << "\n";
}