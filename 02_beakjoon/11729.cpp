#include <bits/stdc++.h>
using namespace std;

int n;

void hanoi(int n, int from, int to)
{
    int other = 6 - from - to;
    if (n == 1)
        cout << from << " " << to << "\n";
    else
    {
        hanoi(n-1, from, other);
        cout << from << " " << to << "\n";
        hanoi(n-1, other, to);
    }        
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << (int)(pow(2, n)-1) << "\n";
    hanoi(n, 1, 3);
}