#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    string r_s;

    cin >> s;
    r_s = s;
    reverse(r_s.begin(), r_s.end());

    if (s == r_s)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}