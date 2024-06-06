#include <bits/stdc++.h>
using namespace std;

int n, l;
int boards[100][100];
int sym_boards[100][100];

int ret;

void func(int arr[100][100])
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int j;
        for (j = 0; j < n-1; j++)
        {
            if (arr[i][j] == arr[i][j+1])
                cnt++;
            else if (arr[i][j]+1 == arr[i][j+1] && cnt >= l)
                cnt = 1;
            else if (arr[i][j]-1 == arr[i][j+1] && cnt >= 0)
                cnt = -l + 1;
            else
                break;
        }

        if (j == n-1 && cnt >= 0)
            ret++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 칸 개수, 경사로 길이 입력
    cin >> n >> l;

    // 지도, 대칭지도 입력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> boards[i][j];
            sym_boards[j][i] = boards[i][j];
        }
    }

    func(boards);
    func(sym_boards);

    cout << ret << "\n";
}