#include <bits/stdc++.h>
using namespace std;

int n;
int boards[64][64];

string quard(int x, int y, int size)
{
    if (size == 1)
        return to_string(boards[x][y]);
    string ret = "";
    for (int i = x; i < x+size; i++)
    {
        for (int j = y; j < y+size; j++)
        {
            if (boards[x][y] != boards[i][j])
            {
                ret += "(";
                ret += quard(x, y, size/2);
                ret += quard(x, y+size/2, size/2);
                ret += quard(x+size/2, y, size/2);
                ret += quard(x+size/2, y+size/2, size/2);
                ret += ")";

                return ret;
            }
        }
    }

    return to_string(boards[x][y]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            boards[i][j] = s[j] - '0';
    }

    string ret = quard(0, 0, n);
    cout << ret << "\n";
}