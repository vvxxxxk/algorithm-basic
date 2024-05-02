#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100];
int visited[100];
int root;
int del_node;
int ret;

void preorder(int r)
{
    visited[r] = true;
    if (r == del_node)
        return;
    if (adj[r].size() == 0)
        ret++;
    if (adj[r].size() == 1 && adj[r][0] == del_node)
        ret++;
    for (int i = 0; i < adj[r].size(); i++)
    {
        int nr = adj[r][i];
        if (!visited[nr])
            preorder(nr);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int parent_number;
    for (int i = 0; i < n; i++)
    {
        cin >> parent_number;

        if (parent_number == -1)
            root = i;
        else
            adj[parent_number].push_back(i);
    }

    cin >> del_node;
    preorder(root);
    cout << ret << "\n";
}