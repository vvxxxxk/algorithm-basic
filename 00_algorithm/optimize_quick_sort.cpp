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

void optimizeQuickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    
    // 최악의 시간복잡도 확률을 줄여서 최적화
    int mid = (left+right) / 2;
    swap(v[left], v[mid]);
    
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
    optimizeQuickSort(v, left, i-1);
    optimizeQuickSort(v, i+1, right);     
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 10000; i > 0; i--)
        v1.push_back(i);
    v2 = v1;
    v3 = v1;
    v4 = v1;

    quickSort(v4, 0, v4.size()-1);

    auto start1 = chrono::high_resolution_clock::now();
    quickSort(v1, 0, v1.size()-1);
    auto end1 = chrono::high_resolution_clock::now();

    chrono::duration<double> ret1 = end1 - start1;
    cout << "quick sort 수행 시간: " << ret1.count() << "sec" << "\n";
    // print(v1);

    auto start2 = chrono::high_resolution_clock::now();
    optimizeQuickSort(v2, 0, v2.size()-1);
    auto end2 = chrono::high_resolution_clock::now();

    chrono::duration<double> ret2 = end2 - start2;
    cout << "optimize quick sort 수행 시간: " << ret2.count() << "sec" << "\n";
    // print(v2);

    auto start3 = chrono::high_resolution_clock::now();
    sort(v3.begin(), v3.end());
    auto end3 = chrono::high_resolution_clock::now();

    chrono::duration<double> ret3 = end3 - start3;
    cout << "표준 라이브러리 quick sort 수행 시간: " << ret3.count() << "sec" << "\n";
    // print(v3);
}