#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void insertionSort(vector<int> &v)
{
    int temp;
    for (int i = 1; i < v.size(); i++)
    {
        temp = v[i];
        for (int j = i-1; j >= 0; j--)
        {
            if (temp < v[j])
            {
                v[j+1] = v[j];      // j 번째 원소를 한 칸 오른쪽으로 이동
                v[j] = temp;        // 기존 j 번째 자리에는 선택된 원소(temp)를 삽입
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {5, 3, 10, 2, 1};

    insertionSort(v);
    print(v); 
}