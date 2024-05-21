#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> v;
vector<int> ret[10];

void go(int left, int right, int level)
{
    int mid = (left + right) / 2;
    ret[level-1].push_back(v[mid]);

    if (left == right)
        return;
    
    go(left, mid-1, level+1);
    go(mid+1, right, level+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    int num;
    for (int i = 0; i < pow(2, k) - 1; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    go(0, v.size() - 1, 1);

    for (int i = 0; i < k; i++)
    {
        for (int j : ret[i])
            cout << j << " ";
        cout << "\n";
    }
}