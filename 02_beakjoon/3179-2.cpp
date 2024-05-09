#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char boards[1504][1504];
int visited[1504][1504];
int swan_visited[1504][1504];
queue<pair<int, int>> swan_q;
queue<pair<int, int>> swan_temp_q;
queue<pair<int, int>> water_q;
queue<pair<int, int>> water_temp_q;

int ret;
int swan_x, swan_y;

void q_clear(queue<pair<int, int>> &q)
{
    queue<pair<int, int>> empty;
    swap(q, empty);
}

bool move_swan()
{
    while (swan_q.size())
    {
        int cx = swan_q.front().first;
        int cy = swan_q.front().second;
        swan_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || swan_visited[nx][ny])
                continue;

            swan_visited[nx][ny] = 1;

            if (boards[nx][ny] == '.')
                swan_q.push({nx, ny});
            else if (boards[nx][ny] == 'X')
                swan_temp_q.push({nx, ny});
            else if (boards[nx][ny] == 'L')
                return true;
        }
    }
    return false;
}

void ice_melting()
{
    while (water_q.size())
    {
        int cx = water_q.front().first;
        int cy = water_q.front().second;
        water_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny])
                continue;
            
            if (boards[nx][ny] == 'X')
            {
                visited[nx][ny] = 1;
                water_temp_q.push({nx, ny});
                boards[nx][ny] = '.';
            }
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
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            boards[i][j] = s[j];
            if (boards[i][j] == 'L')
            {
                swan_x = i;
                swan_y = j;
            }
            if (boards[i][j] == '.' || boards[i][j] == 'L')
            {
                visited[i][j] = 1;
                water_q.push({i, j});
            }
        }
    }

    swan_q.push({swan_x, swan_y});
    swan_visited[swan_x][swan_y] = 1;
    while (true)
    {
        if (move_swan())
            break;
        ice_melting();
        water_q = water_temp_q;
        swan_q = swan_temp_q;
        q_clear(water_temp_q);
        q_clear(swan_temp_q);
        ret++;
    }
    cout << ret << "\n";
}