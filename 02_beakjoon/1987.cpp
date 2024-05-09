#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int boards[20][20];
int visited[20][20];
int alphabet[26];
int ret;

void dfs(int x, int y, int cnt)
{
    ret = max(ret, cnt);
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny])
            continue;
        
        if (alphabet[boards[nx][ny]] == 0)
        {
            visited[nx][ny] = 1;
            alphabet[boards[nx][ny]] = 1;
            cnt++;

            dfs(nx, ny, cnt);

            visited[nx][ny] = 0;
            alphabet[boards[nx][ny]] = 0;
            cnt--;
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
            boards[i][j] = s[j] - 'A';
    }

    visited[0][0] = 1;
    alphabet[boards[0][0]] = 1;
    ret = 1;
    dfs(0, 0, ret);

    cout << ret << "\n";
}