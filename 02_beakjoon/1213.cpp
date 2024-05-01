#include <iostream>
using namespace std;

int alpabet[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        alpabet[s[i]-'A']++;
    
    int odd_cnt = 0;
    int mid = -1;
    for (int i = 0; i < 26; i++)
    {
        if (alpabet[i] % 2 != 0)
        {
            odd_cnt++;
            mid = i;
        }
    }

    string result = "";
    if (mid >= 0)
    {
        result += char('A' + mid);
        alpabet[mid]--;
    }

    if (odd_cnt > 1)
    {
        cout << "I'm Sorry Hansoo" << "\n";
    }
    else
    {
        for (int i = 25; i >= 0; i--)
        {
            while (alpabet[i] > 0)
            {
                result = char('A' + i) + result;
                result = result + char('A' + i);
                alpabet[i] -= 2;
            }
        }
        
        cout << result << "\n";
    }
}