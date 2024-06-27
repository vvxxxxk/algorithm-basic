#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}


void merge(vector<int> &v, int left, int mid, int right)
{
    cout << "left: " << left << ", mid: " << mid << ", right: " << right << "\n";
    // 두 개의 서브 vector 생성
    vector<int> left_sub_v(mid-left+1);
    vector<int> right_sub_v(right-mid);

    // 서브 vector에 값 할당
    for (int i = 0; i < left_sub_v.size(); i++)
        left_sub_v[i] = v[left+i];
    for (int i = 0; i < right_sub_v.size(); i++)
        right_sub_v[i] = v[mid+i+1];

    // 서브 vector 병합
    int i = 0;      // left 서브 vector 인덱스
    int j = 0;      // right 서브 vector 인덱스
    int k = left;   // 원본 vector 인덱스 
    int left_length = left_sub_v.size();
    int right_length = right_sub_v.size();

    while (i < left_length && j < right_length)
    {
        if (left_sub_v[i] <= right_sub_v[j])
            v[k] = left_sub_v[i++];
        else
            v[k] = right_sub_v[j++];
        k++;
    }

    // 남은 요소 복사
    while (i < left_length)
        v[k++] = left_sub_v[i++];
    while (j < right_length)
        v[k++] = right_sub_v[j++];
}

// 병합 정렬 함수
void mergeSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left+right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);

    merge(v, left, mid, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = {89, 82, 27, 89, 68, 88, 62, 32, 2, 37};

    mergeSort(v, 0, v.size()-1);
    print(v);
}
