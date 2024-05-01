#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    // set은 중복이 없고 자동 정렬되는 특징을 가진다.
    set<int> se;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        se.insert(tmp);
    }

    auto pre_it = se.begin();
    auto suf_it = --se.end();
    
    int cnt = 0;
    while (*pre_it < *suf_it)
    {
        int sum = *pre_it + *suf_it;
        
        if (sum < m)
            pre_it++;
        else if (sum > m)
            suf_it--;
        else
        {
            cnt++;
            pre_it++;
            suf_it--;
        }
    }
    
    cout << cnt << "\n";
}