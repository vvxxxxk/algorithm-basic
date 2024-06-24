#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void quickSort(vector<int> &v)
{
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {-2, -3, 5, 3, 10, 2, 1, -1, 1, 2};

    quickSort(v);
    print(v); 
}