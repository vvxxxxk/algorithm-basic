#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n)
    {
        int cnt = 1;
        int result = 1;

        while(true)
        {
            if (cnt % n == 0)
            {
                cout << result << "\n";
                break;
            }
            else
            {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                result++;
            }
        }
    }
}