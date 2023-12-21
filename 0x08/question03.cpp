/*
    https://www.acmicpc.net/problem/2504
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);

    stack<char> s;
    int partial_num = 1;
    int result_num = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            partial_num *= 2;
            s.push('(');
        }
        else if (str[i] == '[')
        {
            partial_num *= 3;
            s.push('[');
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                result_num = 0;
                break;
            }
            if(str[i-1] == '(')
            {
                result_num += partial_num;
                partial_num /= 2;
                s.pop();
            }
            else
            {
                partial_num /= 2;
                s.pop();
            }

        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                result_num = 0;
                break;
            }
            if(str[i-1] == '[')
            {
                result_num += partial_num;
                partial_num /= 3;
                s.pop();
            }
            else
            {
                partial_num /= 3;
                s.pop();
            }
        }
    }

    if (!s.empty())
        result_num = 0;

    cout << result_num << "\n";
}