/*
    https://www.acmicpc.net/problem/10845
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        string cmd, front_cmd, back_cmd;
        getline(cin, cmd);

        front_cmd = cmd.substr(0, cmd.find(" "));
        back_cmd = cmd.substr(cmd.find(" ") + 1, cmd.length());

        if (!front_cmd.compare("push"))
        {
            q.push(stoi(back_cmd));
        }
        else if (!front_cmd.compare("pop"))
        {
            if(q.empty())
                cout << -1 << "\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (!front_cmd.compare("size"))
        {
            cout << q.size() << "\n";
        }
        else if (!front_cmd.compare("empty"))
        {
            if(q.empty())
                cout << 1 << "\n";
            else    
                cout << 0 << "\n";
        }
        else if (!front_cmd.compare("front"))
        {
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if (!front_cmd.compare("back"))
        {
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }

}