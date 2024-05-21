#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, m, h;
int visited[30][10];
int ret = INF;

bool check()
{
    for (int i = 0; i < n; i++)
    {
        int start = i;
        for (int j = 0; j < h; j++)
        {
            if (visited[j][start])
                start++;
            else if (visited[j][start-1])
                start--;
        }

        if (i != start)
            return false;
    }

    return true;
}

void go(int here, int size)
{
    if (ret <= size || size > 3)
        return;
    
    if (check())
    {
        ret = min(ret, size);
        return;
    }

    for (int i = here; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] || visited[i][j-1] || visited[i][j+1])
                continue;

            visited[i][j] = 1;
            go (i, size + 1);
            visited[i][j] = 0;   
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 세로선 개수, 가로선 개수, 가로선 위치 개수
    cin >> n >> m >> h;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        visited[a-1][b-1] = 1;
    }

    go(0, 0);

    if (ret == INF)
        cout << -1 << "\n";
    else
        cout << ret << "\n";
}