#include <bits/stdc++.h>
using namespace std;

int n, k;
int ret = -1;
vector<int> v(500001);

void merge(vector<int> &v, int left, int mid, int right)
{
    // 서브 벡터 생성
    vector<int> left_vec(mid-left+1);
    vector<int> right_vec(right-mid);

    // 서브 벡터 초기화
    for (int i = 0; i < left_vec.size(); i++)
        left_vec[i] = v[left+i];
    for (int i = 0; i < right_vec.size(); i++)
        right_vec[i] = v[mid+i+1];
    
    // 서브 벡터 merge & sort
    int left_idx = 0;           // 왼쪽 서브 벡터 인덱스
    int right_idx = 0;          // 오른쪽 서브 벡터 인덱스
    int idx = left;             // 원본 벡터 인덱스
    int left_vec_size = left_vec.size();
    int right_vec_size = right_vec.size();

    // left_idx, right_idx가 각각의 서브 벡터 사이즈를 초과하면 반복 종료
    // 왼쪽 서브 벡터 값과 오른쪽 서브 벡터 값을 비교한 후, 정렬 기준에 맞게 원본 벡터에 삽입
    while (left_idx < left_vec_size && right_idx < right_vec_size)
    {
        if (left_vec[left_idx] <= right_vec[right_idx])
            v[idx] = left_vec[left_idx++];
        else
            v[idx] = right_vec[right_idx++];
        
        k--;
        if (k == 0)
            ret = v[idx];
        
        idx++;    
    }

    // 왼쪽 서브 벡터에 남은 요소가 있다면 복사
    while (left_idx < left_vec_size)
    {
        v[idx] = left_vec[left_idx++];
        k--;
        if (k == 0)
            ret = v[idx];
        idx++;
    }
    // 오른쪽 서브 벡터에 남은 요소가 있다면 복사
    while (right_idx < right_vec_size)
    {
        v[idx] = right_vec[right_idx++];
        k--;
        if (k == 0)
            ret = v[idx];
        idx++;
    }
}

void merge_sort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);
    merge(v, left, mid, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }

    merge_sort(v, 0, n-1);
    cout << ret << "\n";
}