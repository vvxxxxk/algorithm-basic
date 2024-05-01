#include <iostream>
using namespace std;

int arr[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string f_name;
        cin >> f_name;

        arr[f_name[0] - 'a']++;
    }

    string ret = "";
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= 5)
            ret += i + 'a'; 
    }

    if (ret != "")
        cout << ret << "\n";
    else
        cout << "PREDAJA" << "\n";
}