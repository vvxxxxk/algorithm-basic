#include <bits/stdc++.h>
using namespace std;

int x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    bitset<7> binary(x);
    cout << binary.count() << "\n";
}