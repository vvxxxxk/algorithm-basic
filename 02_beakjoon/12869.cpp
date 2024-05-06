#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> scv(3);
int boards[64][64][64];
int visited[64][64][64];
int att[6][3] = { {9, 3, 1},
                  {9, 1, 3},
                  {3, 1, 9},
                  {3, 9, 1},
                  {1, 3, 9},
                  {1, 9, 3}};

struct A
{
    int a, b, c;
};

int ret;

void bfs(int a, int b, int c)
{
    visited[a][b][c] = 1;
    queue<A> q;
    q.push({a, b, c});

    while (q.size())
    {
        int ca = q.front().a;
        int cb = q.front().b;
        int cc = q.front().c;
        q.pop();

        if (visited[0][0][0])
            break;
        
        for (int i = 0; i < 6; i++)
        {
            int na = max(0, ca-att[i][0]);
            int nb = max(0, cb-att[i][1]);
            int nc = max(0, cc-att[i][2]);

            if (visited[na][nb][nc])
                continue;
            
            visited[na][nb][nc] = visited[ca][cb][cc] + 1;
            q.push({na, nb, nc});
        }
    }
    ret = visited[0][0][0] - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> scv[i];
    
    bfs(scv[0], scv[1], scv[2]);
    cout << ret << "\n";
}