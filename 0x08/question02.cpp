/*
    https://www.acmicpc.net/problem/10799
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

    // ( : 1
    // ) : 2
    stack<int> s;
    int result = 0;
    int previous_char = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')   // 새로운 쇠 막대기
        {
            s.push(1);
            previous_char = 1;
        }
        else if(str[i] == ')' && previous_char == 1)    // 레이저
        {
            s.pop();
            result += s.size();
            previous_char = 2;
        }
        else if(str[i] == ')' && previous_char == 2)    // 쇠 막대기 마지막 잘린 조각 (개수+1)
        {
            s.pop();
            result += 1;
            previous_char = 2;
        }
    }
    
    cout << result << "\n";
}