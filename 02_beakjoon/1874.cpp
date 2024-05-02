#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
string ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
        cin >> v[i-1];
    
    int v_idx = 0;
    int i = 1;
    while (v_idx < n)
    {
        // 스택이 비어있을 때
        if (s.empty())
        {
            s.push(i);
            ret += "+";
            i += 1;
        }
        // 스택이 비어있지 않을 때
        else
        {
            // 스택 마지막 요소가 i와 같을 때
            if (s.top() == v[v_idx])
            {
                s.pop();
                ret += "-";
                v_idx += 1;
            }
            // 스택 마지막 요소가 i와 다를 때
            else
            {
                // i가 n의 범위를 넘어갔다면
                if (i > n)
                {
                    ret = "NO";
                    break;
                }
                else
                {
                    s.push(i);
                    ret += "+";
                    i += 1;
                }
            }
        }
    }

    if (ret == "NO")
        cout << ret << "\n";
    else
    {
        for (int i = 0; i < ret.size(); i++)
            cout << ret[i] << "\n";
    }
}