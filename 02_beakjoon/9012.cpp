#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string ps;
        cin >> ps;
        stack<int> s;
        string result = "";
        for (int i = 0; i < ps.length(); i++)
        {
            if (ps[i] == '(')
                s.push(1);
            else if (ps[i] == ')')
            {
                if (s.size() < 1)
                {
                    result = "NO";
                    continue;
                }
                else
                    s.pop();
            }
        }

        if (s.size() > 0)
            result = "NO";
        else if (result.compare("NO"))
            result = "YES";

        cout << result << "\n";
    }
}