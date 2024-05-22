#include <bits/stdc++.h>
using namespace std;

int n;
int boards[11][11];
int visited[11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 999999999;
int ret = INF;

// 꽃을 심을 수 있는지 체크하는 메서드
bool check(int x, int y)
{
    if (visited[x][y])
        return false;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
            return false;
    }

    return true;
}

// 꽃을 심고 비용을 리턴하는 메서드
int setFlower(int x, int y)
{
    int price = boards[x][y];
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        visited[nx][ny] = 1;
        price += boards[nx][ny];
    }

    return price;
}

// 꽃을 지우는 메서드
void eraseFlower(int x, int y)
{
    visited[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        visited[nx][ny] = 0;
    }
}

void flower(int cnt, int sum)
{
    if (cnt == 3)
    {
        ret =  min(ret, sum);
        return ;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i, j))
            {
                int temp = setFlower(i, j);
                flower(cnt + 1, sum + temp);
                eraseFlower(i, j);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> boards[i][j];
    }

    flower(0, 0);
    cout << ret << "\n";
}