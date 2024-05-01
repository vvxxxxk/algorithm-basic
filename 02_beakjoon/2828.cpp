#include <bits/stdc++.h>
using namespace std;

int N, M, J;
int start = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> J;

    
    int ret = 0;
    int p;
    for (int i = 0; i < J; i++)
    {
        cin >> p;

        // 사과 좌표 - 바구니 범위
        int mx = p - (start+M-1);

        if (start < p)      // 바구니 오른쪽으로 이동
        {
            if (mx <= 0)
                continue;
            
            // r만큼 이동
            ret += mx;
            start += mx;
        }
        else if (start > p) // 바구니 왼쪽으로 이동
        {
            ret += start - p;
            start -= start - p;
        }
    }
    cout << ret << "\n";
}