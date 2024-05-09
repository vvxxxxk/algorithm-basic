#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int boards[1504][1504];
int visited[1504][1504];

int swan_visited[1504][1504];

vector<pair<int, int>> water_vec;
vector<pair<int, int>> swan_vec(1);

queue<pair<int, int>> swan_q;
queue<pair<int, int>> ice_q;

bool flag = false;
int ret;

void find_swan(int x, int y)
{
    swan_visited[x][y] = 1;
    queue<pair<int, int>> q;
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

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || swan_visited[nx][ny])
                continue;

            if (boards[nx][ny] == 0)    // 물
            {
                q.push({nx, ny});
                swan_visited[nx][ny] = 1;
            }

            if (boards[nx][ny] == 1)    // 얼음
                swan_q.push({nx, ny});

            if (boards[nx][ny] == 2)    // 백조
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
}


void melt_ice(int x, int y)
{
    visited[x][y] = 1;
    queue<pair<int, int>> q;
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

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny])
                continue;
            
            if (boards[nx][ny] != 1)    // 얼음이 아닐 때
            {
                visited[nx][ny] = visited[cx][cy];
                q.push({nx, ny});
            }
            else                        // 얼음 일 때
                ice_q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    string input;
    for (int i = 0; i < r; i++)
    {
        cin >> input;
        for (int j = 0; j < input.size(); j++)
        {
            if (input[j] == '.')    // 물
            {
                boards[i][j] = 0;
                water_vec.push_back({i, j});
            }
            if (input[j] == 'X')    // 얼음
            {
                boards[i][j] = 1;
            }
            if (input[j] == 'L')    // 백조
            {
                boards[i][j] = 2;
                water_vec.push_back({i, j});
                swan_vec[0] = {i, j};
            }
        }
    }


    while (!flag)
    {
        // 백조 찾기
        for (int i = 0; i < swan_vec.size(); i++)
        {
            int x = swan_vec[i].first;
            int y = swan_vec[i].second;

            if (swan_visited[x][y])
                continue;

            find_swan(x, y);
        }
        if (!flag)
            ret++;
        swan_vec.clear();
        while (swan_q.size())
        {
            
            int cx = swan_q.front().first;
            int cy = swan_q.front().second;
            swan_q.pop();

            swan_vec.push_back({cx, cy});
        }
        

        for (int i = 0; i < water_vec.size(); i++)
        {
            int x = water_vec[i].first;
            int y = water_vec[i].second;

            if (visited[x][y])
                continue;

            melt_ice(x, y);
        }

        water_vec.clear();
        while (ice_q.size())
        {
            int cx = ice_q.front().first;
            int cy = ice_q.front().second;
            ice_q.pop();

            boards[cx][cy] = 0;
            water_vec.push_back({cx, cy});
        }
    }

    cout << ret << "\n";
}