#include <iostream>
using namespace std;

int arr[100004];
int psum_arr[100004];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        psum_arr[i] = psum_arr[i-1] + arr[i];
    }

    int max = -10000001;
    for (int i = k; i <= n; i++)
    {
        int temp = psum_arr[i] - psum_arr[i-k];
        if (max < temp)
            max = temp;
    }

    cout << max << "\n";
}