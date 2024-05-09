#include <bits/stdc++.h>
using namespace std;
void fast_io() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

const int MAX = 200000;
int n, k;
int visited[MAX + 4];
int cnt[MAX + 4];

void bfs(int x)
{
    visited[x] = 1;
    cnt[x] = 1;
    queue<int> q;
    q.push(x);

    while (q.size())
    {
        int now = q.front();
        q.pop();

        for (int next : {now-1, now+1, now*2})
        {
            if (0 <= next && next <= MAX)
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if (visited[next] == visited[now] + 1)
                {
                    cnt[next] += cnt[now];
                }
            }
        }
    }    
}

int main()
{
    fast_io();

    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n";
        cout << 1 << "\n";
        return 0;
    }
    bfs(n);
    cout << visited[k] - 1 << "\n";
    cout << cnt[k] << "\n";
}