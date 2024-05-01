#include <iostream>
using namespace std;

int arr[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        
        if (s[i] >= 65 && s[i] <= 90)            // 대문자
        {
            if (s[i] + 13 > 90)
                s[i] = s[i] + 13 - 26;
            else
                s[i] = s[i] + 13;
        }
        else if(s[i] >= 97 && s[i] <= 122)      // 소문자
        {
            if (s[i] + 13 > 122)
                s[i] = s[i] + 13 - 26;
            else
                s[i] = s[i] + 13;
        }
    }

    cout << s << "\n";
}