#include <bits/stdc++.h>
using namespace std;

int N, M;
int mx;
int w_cnt;
int boards[10][10];
int visited[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> v;
vector<pair<int, int>> virus_vec;
vector<pair<int, int>> empty_vec;

void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (visited[nx][ny] == 0 && boards[nx][ny] == 0) 
            dfs(nx, ny);
    }
}

int check()
{
    int v_cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 1)
            {
                v_cnt++;
                visited[i][j] = 0;
            }
        }
    }

    return (N*M) - v_cnt - w_cnt - 3;
}


void combi(int start)
{
    if (v.size() == 3)
    {
        for (int i : v)
            boards[empty_vec[i].first][empty_vec[i].second] = 1;
        for (auto p : virus_vec)
            dfs(p.first, p.second);
        mx = max(mx, check());
        for (int i : v)
            boards[empty_vec[i].first][empty_vec[i].second] = 0;
        return;
    }

    for (int i = start + 1; i < empty_vec.size(); i++)
    {
        v.push_back(i);
        combi(i);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> boards[i][j];
            if (boards[i][j] == 0)
                empty_vec.push_back({i, j});
            if (boards[i][j] == 2)
                virus_vec.push_back({i, j});
        }
    }


    mx = -1;
    w_cnt = (N*M) - virus_vec.size() - empty_vec.size();
    combi(-1);

    cout << mx << "\n";
}