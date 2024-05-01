#include <bits/stdc++.h>
using namespace std;

int H, W;
int boards[104][104];

bool isCloud(int idx)
{
    return (idx == 'c');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;

    string s;
    for (int i = 0; i < H; i++)
    {
        cin >> s;
        bool is_cloud = false;
        int idx;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'c')
            {
                boards[i][j] = 0;
                is_cloud = true;
                idx = 0;
            }
            else if (is_cloud)
                boards[i][j] = ++idx;
            else
                boards[i][j] = -1;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << boards[i][j] << " ";
        cout << "\n";
    }
}