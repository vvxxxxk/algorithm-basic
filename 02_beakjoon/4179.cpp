#include <bits/stdc++.h>
using namespace std;

int r, c;
int dy[]={-1,0,1,0};
int dx[] ={0,1,0,-1}; 
int boards[1004][1004];
int j_visited[1004][1004];
int f_visited[1004][1004];
queue<pair<int, int>> j_q;
queue<pair<int, int>> f_q;
const int INF = 987654321;

int ret;

void f_bfs()
{
    while (f_q.size())
    {
        int cx = f_q.front().first;
        int cy = f_q.front().second;
        f_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            
            if (f_visited[nx][ny] != INF)
                continue;
            if (boards[nx][ny] == 0)
                continue;
            
            f_visited[nx][ny] = f_visited[cx][cy] + 1;
            f_q.push({nx, ny});            
        }
    }    
}

void j_bfs()
{
    while (j_q.size())
    {
        int cx = j_q.front().first;
        int cy = j_q.front().second;
        j_q.pop();

        // 가장자리에 있는 경우
        if (cx == r-1 || cy == c-1 || cx == 0 || cy == 0)
        {
            ret = j_visited[cx][cy];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            
            if (j_visited[nx][ny])
                continue;
            if (boards[nx][ny] == 0)
                continue;
            
            // 불이 지훈이보다 빠르거나 같을 경우
            if (f_visited[nx][ny] <= j_visited[cx][cy]+1)
                continue;
            
            j_visited[nx][ny] = j_visited[cx][cy] + 1;
            j_q.push({nx, ny});                      
        }
    }    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    string s;

    // 불이 없는 경우를 고려
    // f_visited 배열의 모든 값을 0이 아닌 매우 큰 값으로 설정
    fill(&f_visited[0][0], &f_visited[0][0] + 1004*1004, INF);
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            // 벽 0, 공간 1, 지훈 2, 불 3
            if (s[j]-'#' == 0)
                boards[i][j] = 0;
            else if (s[j]-'.' == 0)
                boards[i][j] = 1;
            else if (s[j]-'J' == 0)
            {
                boards[i][j] = 2;
                j_q.push({i, j});
                j_visited[i][j] = 1;
            }
            else if (s[j]-'F' == 0)
            {
                boards[i][j] = 3;
                f_q.push({i, j});
                f_visited[i][j] = 1;
            }
        }
    }

    // 불 bfs
    f_bfs();
    // 지훈 bfs
    j_bfs();

    if (ret != 0)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE" << "\n";
}