#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string pattern;
    string prefix, suffix;

    cin >> n >> pattern;
    prefix = pattern.substr(0, pattern.find('*'));
    suffix = pattern.substr(pattern.find('*')+1);

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        // ab*ab 라는 패턴일 때 아래 조건식을 검사하지 않으면, ab가 통과될 수 있음
        if (prefix.length() + suffix.length() > str.length())
            cout << "NE" << "\n";
        else
        {
            if (prefix == str.substr(0, prefix.length()) && suffix == str.substr(str.length() - suffix.length()))
                cout << "DA" << "\n";
            else
                cout << "NE" << "\n";
        }
    }
}