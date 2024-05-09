#include <bits/stdc++.h>
using namespace std;

int n;
int ret;

vector<int> num_vec;
vector<char> oper_vec;

int oper(char c, int a, int b)
{
    if (c == '+')
        return a + b;
    else if (c == '*')
        return a * b;
    else    // c == '-'
        return a - b;
}

void go(int start, int num)
{
    if (start == num_vec.size() - 1)
    {
        ret = max(ret, num);
        return;
    }

    go(start+1, oper(oper_vec[start], num, num_vec[start+1]));
    
    if (start+2 <= num_vec.size() - 1)
    {
        int temp = oper(oper_vec[start+1], num_vec[start+1], num_vec[start+2]);
        go(start+2, oper(oper_vec[start], num, temp));
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ret = numeric_limits<int>::lowest();

    cin >> n;
    char c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (i % 2 == 0)
            num_vec.push_back(c-'0');
        else
            oper_vec.push_back(c);
    }

    go(0, num_vec[0]);
    cout << ret << "\n";
}