#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
int cnt = 0;
int mx = -1;
vector<int> adj[10001];
int visited[10001];
vector<int> ret[10001];

void preorder(int root)
{
    visited[root] = 1;
    cnt++;
    for (int i = 0; i < adj[root].size(); i++)
    {
        int next = adj[root][i];
        if (visited[next] == 1)
            continue;
        
        preorder(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        preorder(i);
        ret[cnt].push_back(i);
        mx = max(mx, cnt);
        cnt = 0;
        fill(&visited[0], &visited[0] + 10001, 0);
    }

    
    sort(ret[mx].begin(), ret[mx].end());
    for (int i = 0; i < ret[mx].size(); i++)
        cout << ret[mx][i] << " ";
    cout << "\n";
}