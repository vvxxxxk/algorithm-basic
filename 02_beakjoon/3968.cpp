#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.size() == 0)
            {
                st.push(s[i]);
                continue;
            }
            
            if (st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }

        if (st.size() == 0)
            cnt++;
    }

    cout << cnt << "\n";
}