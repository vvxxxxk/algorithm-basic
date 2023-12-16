/*
    https://www.acmicpc.net/problem/10828
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        string cmd, front_cmd, back_cmd;
        getline(cin, cmd);

        front_cmd = cmd.substr(0, cmd.find(" "));
        back_cmd = cmd.substr(cmd.find(" ") + 1, cmd.length());
        // cout << "frond_cmd: " << front_cmd << "\n";
        // cout << "back_cmd: " << back_cmd << "\n";

        if(!front_cmd.compare("push"))
        {
            s.push(stoi(back_cmd));
        }
        else if(!front_cmd.compare("pop"))
        {
            if(s.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
            s.pop();
        }
        else if(!front_cmd.compare("size"))
        {
            cout << s.size() << "\n";
        }
        else if(!front_cmd.compare("empty"))
        {
            if(s.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(!front_cmd.compare("top"))
        {
            if(s.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
        }

    }
}