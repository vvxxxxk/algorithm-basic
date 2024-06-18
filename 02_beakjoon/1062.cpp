#include <bits/stdc++.h>
using namespace std;

int n, k;
string str;
int words[51];

int count(int mask)
{
    int cnt = 0;
    for (int word : words)
    {
        if (word && (word & mask) == word)
            cnt++;
    }

    return cnt;
}

int go(int index, int m, int mask)
{
    if (m < 0)
        return 0;
    
    if (index == 26)
        return count(mask);

    int ret = go(index+1, m-1, mask | (1 << index));
    if (index != 'a' - 'a' && index != 'c' - 'a' && index != 'i' - 'a' && index != 'n' - 'a' && index != 't' - 'a')
        ret = max(ret, go(index+1, m, mask));

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (char c : str)
            words[i] = words[i] | (1 << (c - 'a'));
    }

    cout << go(0, k, 0) << "\n";
}