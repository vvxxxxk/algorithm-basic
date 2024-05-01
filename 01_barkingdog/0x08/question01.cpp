/*
    https://www.acmicpc.net/problem/4949
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true)
    {
        string str;
        getline(cin, str);

        if(!str.compare("."))
            break;
        
        // 소괄호: 1
        // 대괄호: 2
        stack<int> s;
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
                s.push(1);
            else if(str[i] == ')')
            {
                if(s.empty() || s.top() == 2)
                {
                    cout << "no" << "\n";
                    break;   
                } 
                else
                    s.pop();
            }
            else if(str[i] == '[')
                s.push(2);
            else if(str[i] == ']')
            {
                if(s.empty() || s.top() == 1)
                {
                    cout << "no" << "\n";
                    break;   
                } 
                else
                    s.pop();
            }

            if(i == str.length() - 1)
            {
                if(s.empty())
                    cout << "yes" << "\n";
                else
                    cout << "no" << "\n";
            }
        }        
    }
}