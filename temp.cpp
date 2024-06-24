#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    if (num == 2)
        return true;
    if (num <= 1 || num % 2 == 0)
        return false;
    double sqrt_num = sqrt(double(num));
    for (int div = 3; div <= sqrt_num; div += 2)
    {
        if (num % div == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 10000000;
    clock_t start, end;
    start = clock();
    for (int i = 0; i < N; i++)
        isPrime(i);
    end = clock();
    cout << (end-start) / ((double)CLOCKS_PER_SEC) << "\n";
}