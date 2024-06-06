#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n; 
char c;
int boards[21];
int mn = INF;

void reverse_coin(int here)
{
    if (here == n)
    {
        int sum = 0;
        for (int i = 1; i < (1 << n); i*=2)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (boards[j] & i)  // 비트가 켜져있을 때 개수 카운트
                    cnt++;
                
            }
            sum += min(cnt, n-cnt); //  min(현재 열의 뒷면 개수, 뒤집은 열의 뒷면 개수)
        }
        mn = min(mn, sum);
        return ;
    }

    reverse_coin(here + 1);         // 동전을 뒤집지 않는 경우 실행
    boards[here] = ~boards[here];   // 동전을 뒤집기
    reverse_coin(here + 1);         // 동전을 뒤집는 경우 실행
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val = 1;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            if (c == 'T')   // 동전이 뒷면일 경우
                boards[i] |= val;
            val *= 2;
        }
    }

    reverse_coin(0);
    cout << mn << "\n";
}