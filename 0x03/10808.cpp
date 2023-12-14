#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    getline(cin, s);

    int arr[26] = {0, };

    for (int i = 0; i < s.length(); i++)
        arr[s[i] - 'a']++;

    for(int i = 0; i < 26; i++)
        cout << arr[i] << ' ';
    cout << "\n\n";
}