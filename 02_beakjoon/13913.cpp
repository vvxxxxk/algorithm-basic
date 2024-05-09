#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k;
int visited[MAX+4];
int prevv[MAX+4];

void bfs(int x)
{
    visited[x] = 1;

    queue<int> q;
    q.push(x);

    while (q.size())
    {
        int here = q.front();
        q.pop();

        if (here == k)
            break;
        
        for (int next : {here-1, here+1, here*2})
        {
            if (next < 0 || next > MAX || visited[next])
                continue;
            
            visited[next] = visited[here] + 1;
            prevv[next] = here;
            q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n";
        cout << n << "\n";
        return 0;
    }

    bfs(n);

    vector<int> path_vec;
    for (int i = k; i != n; i = prevv[i])
        path_vec.push_back(i);
    path_vec.push_back(n);
    reverse(path_vec.begin(), path_vec.end());
    
    cout << visited[k] - 1 << "\n";
    for (int i : path_vec)
        cout << i << " ";
    cout << "\n";
}