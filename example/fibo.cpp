#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    int result = fibo(5);
    cout << "result: " << result << "\n";
}