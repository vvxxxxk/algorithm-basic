#include <bits/stdc++.h>
using namespace std;

bool isVowel(int idx)
{
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string pwd;
    while (true)
    {
        cin >> pwd;
        if (pwd == "end")
            break;
        
        bool is_include_v = 0;
        int l_cnt = 0;
        int v_cnt = 0;
        bool flag = 0;
        int prev = -1;
        for (int i = 0; i < pwd.size(); i++)
        {
            int idx = pwd[i];
            if (isVowel(idx))
            {
                v_cnt++;
                l_cnt = 0;
                is_include_v = 1;
            }
            else
            {
                l_cnt++;
                v_cnt = 0;
            }

            if (l_cnt == 3 || v_cnt == 3)
                flag = 1;

            if (i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o'))
                flag = 1;
            
            prev = idx;
        }

        if (is_include_v == 0)
            flag = 1;
        
        if (flag)
            cout << "<" << pwd << ">" << " is not acceptable." << "\n";
        else
            cout << "<" << pwd << ">" << " is acceptable." << "\n";
    }
}