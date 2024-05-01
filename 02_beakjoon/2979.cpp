#include <iostream>
using namespace std;

int arr[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++)
    {
        int start, end;
        cin >> start >> end;
        for (int j = start; j < end; j++)
            arr[j]++;
    }

    int price = 0;
    for (int i = 1; i < 101; i++)
    {
        if (arr[i] == 1)
            price += a;
        else if (arr[i] == 2)
            price += b * 2;
        else if (arr[i] == 3)
            price += c * 3;
    }

    cout << price << "\n";    
}