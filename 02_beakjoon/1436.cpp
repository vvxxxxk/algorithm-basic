#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;

    int number = 666;
    int cnt = 0;
    int result;
    while(n != cnt)
    {
        string s = to_string(number);
        if (s.find("666") != string::npos)
            cnt++;
        result = number++;
    }
    cout << result << "\n";
}