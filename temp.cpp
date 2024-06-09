#include <bits/stdc++.h>
using namespace std;

int a1, a0, c, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a1 >> a0 >> c >> n;

    if (a1*n + a0 <= c*n && a1 <= c)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}