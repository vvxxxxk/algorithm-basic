#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void selectionSort(vector<int> &v)
{
    int temp, min_index;
    for (int i = 0; i < v.size()-1; i++)
    {
        min_index = i;
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[j] < v[min_index])
                min_index = j;
        }
        // swap
        temp = v[min_index];
        v[min_index] = v[i];
        v[i] = temp;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {5, 3, 10, 2, 1};

    selectionSort(v);
    print(v); 
}