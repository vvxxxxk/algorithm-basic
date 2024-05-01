#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ret;

bool isNum(int idx)
{
    if (idx >= '0' && idx <= '9')
        return true;
    return false;
}

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string s;
    string str_num = "";
    bool is_num = false;
    while(n--)
    {
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            is_num = isNum(s[i]);
            if (is_num)
                str_num += s[i];
            
            if (str_num.size() && (!is_num || i == s.size() -1))
            {
                while (str_num.size() != 1 && str_num[0] == '0')
                {
                    str_num.erase(str_num.begin());
                }

                ret.push_back(str_num);
                str_num = "";
            }
        }
    }

    sort(ret.begin(), ret.end(), cmp);
    for (string r : ret)
        cout << r << "\n";
}