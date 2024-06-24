#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void quickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    
    // 분할
    int pivot = v[left];
    int i = left;
    for (int j = left+1; j <= right; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[left], v[i]);

    // 정복
    quickSort(v, left, i-1);
    quickSort(v, i+1, right);    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {89, 82, 27, 89, 68, 88, 62, 32, 2, 37};

    quickSort(v, 0, v.size()-1);
    print(v); 
}