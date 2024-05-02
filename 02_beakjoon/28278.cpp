#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        int cmd;
        cin >> cmd;

        // 명령1. 정수를 입력받고 스택에 넣는다.
        if (cmd == 1)
        {
            int num;
            cin >> num;

            s.push(num);
        }
        // 명령2. 스택에 정수가 있다면 맨 위의 정수를 빼고 출력하고 없다면 -1을 출력
        if (cmd == 2)
        {
            if (s.size())
            {
                cout << s.top() << "\n";
                s.pop();
            }
            else
                cout << -1 << "\n";
        }
        // 명령3. 스택에 들어있는 정수의 개수를 출력
        if (cmd == 3)
            cout << s.size() << "\n";
        // 명령4. 스택이 비어있으면 1, 비어있지 않으면 0을 출력
        if (cmd == 4)
            cout << s.empty() << "\n";
        // 명령5. 스택에 정수가 있다면 맨 위의 정수를 출력하고 없다면 -1을 출력
        if (cmd == 5)
        {
            if (s.size())
                cout << s.top() << "\n";
            else
                cout << -1 << "\n";
        }
    }
    
}