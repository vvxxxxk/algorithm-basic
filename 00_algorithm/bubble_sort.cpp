#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void bubbleSort(vector<int> &v)
{
    int temp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < v.size()-i; j++)
        {
            if (v[j] < v[j-1])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp; 
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

    bubbleSort(v);
    print(v); 
}