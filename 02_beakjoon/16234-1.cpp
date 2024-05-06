#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int boards[50][50];
int visited[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int union_no;
bool is_move = true;

int ret;

// 연합 표시 bfs
void union_bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = ++union_no;
    q.push({x, y});

    while (q.size())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // nx, ny가 맵을 벗어난 경우 continue;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            // 이미 연합된 나라가 있는 경우 continue;
            if (visited[nx][ny])
                continue;
            
            // 연합 조건(L <= interval <= R)에 맞는 경우
            int interval = abs(boards[cx][cy] - boards[nx][ny]);
            if (L <= interval && interval <= R)
            {
                visited[nx][ny] = visited[cx][cy];
                q.push({nx, ny});

                // 연합이 하나라도 생성된 경우, is_move = true;
                is_move = true;
            }   
        }
    }
}

// 인구 이동 bfs
void move_bfs(int x, int y)
{
    // 연합 좌표 리스트, 연합 인구 수
    vector<pair<int, int>> union_vec = {{x, y}};
    int union_pop_sum = boards[x][y];

    queue<pair<int, int>> q;
    int cur_union_no = visited[x][y];
    visited[x][y] = 0;
    q.push({x, y});

    while (q.size())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // nx, ny가 맵을 벗어난 경우 continue;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            // 연합한 나라가 아닐 경우 continue;
            if (cur_union_no != visited[nx][ny])
                continue;
            
            // 이미 방문한 경우 continue;
            if (!visited[nx][ny])
                continue;
            
            union_vec.push_back({nx, ny});
            union_pop_sum += boards[nx][ny];
            visited[nx][ny] = 0;

            q.push({nx, ny});
        }
    }

    // 인구 이동
    for (int i = 0; i < union_vec.size(); i++)
    {
        int new_pop = union_pop_sum / union_vec.size();
        boards[union_vec[i].first][union_vec[i].second] = new_pop;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> boards[i][j];
    }

    while (is_move)
    {
        is_move = false;
        union_no = 1;
    
        // 연합 조건에 일치한다면, visited에 연합 번호로 표시
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j])
                    continue;
                union_bfs(i, j);
            }
        }

        // 인구 이동이 없는 경우, break;
        // 인구 이동이 발생한 경우, ret++;
        if (!is_move)
            break;
        else
            ret++;
        
        // 인구 이동
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                move_bfs(i, j);
            }
        }
    }

    cout << ret << "\n";
}