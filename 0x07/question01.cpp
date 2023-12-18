/*
    https://www.acmicpc.net/problem/10866
*/
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    deque<int> d;
    for (int i = 0; i < n; i++)
    {
        string cmd, front_cmd, back_cmd;
        getline(cin, cmd);

        front_cmd = cmd.substr(0, cmd.find(" "));
        back_cmd = cmd.substr(cmd.find(" ") + 1, cmd.length());

        if (!front_cmd.compare("push_front"))
        {
            d.push_front(stoi(back_cmd));
        }
        else if (!front_cmd.compare("push_back"))
        {
            d.push_back(stoi(back_cmd));
        }
        else if (!front_cmd.compare("pop_front"))
        {
            if (d.empty())
                cout << -1 << "\n";
            else
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if (!front_cmd.compare("pop_back"))
        {
            if (d.empty())
                cout << -1 << "\n";
            else
            {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if (!front_cmd.compare("size"))
        {
            cout << d.size() << "\n";
        }
        else if (!front_cmd.compare("empty"))
        {
            if (d.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (!front_cmd.compare("front"))
        {
            if (d.empty())
                cout << -1 << "\n";
            else
                cout << d.front() << "\n";
        }
        else if (!front_cmd.compare("back"))
        {
            if (d.empty())
                cout << -1 << "\n";
            else
                cout << d.back() << "\n";
        }   
    }
}