#include <bits/stdc++.h>
using namespace std;

int N, C;
map<int, int> mp;
map<int, int> mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return mp_first[a.second] < mp_first[b.second];
    
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        mp[input]++;

        if (mp_first[input] == 0)
            mp_first[input] = i + 1;
    }

    for (auto it : mp)
        v.push_back({it.second, it.first});

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].first; j++)
            cout << v[i].second << " ";
    }
    cout << "\n";
}