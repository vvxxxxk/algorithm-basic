#include <bits/stdc++.h>
using namespace std;

const int INF = 99999;

int n;
int mp, mf, ms, mv;
int cur_p, cur_f, cur_s, cur_v, cur_c;
int mn_c = INF;
map<int, vector<vector<int>>> ret;

struct food
{
    int p, f, s, v, c;
};
food foods[16];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
        cin >> foods[i].p >> foods[i].f >> foods[i].s >> foods[i].v >> foods[i].c;


    // 비트마스킹을 사용해서 모든 경우의 수 탐색
    for (int i = 0; i < (1 << n); i++)
    {
        cur_p = cur_f = cur_s = cur_v = cur_c = 0;
        vector<int> v;
        
        for (int j = 0; j < n; j++)
        {
            // 해당하는 재료가 포함된 경우
            if (i & (1 << j))   
            {
                v.push_back(j+1);       // 재료 번호 push_back
                cur_p += foods[j].p;
                cur_f += foods[j].f;
                cur_s += foods[j].s;
                cur_v += foods[j].v;
                cur_c += foods[j].c;
            }
        }

        // 모든 영양소의 최소 기준치 이상일 경우
        if (cur_p >= mp && cur_f >= mf && cur_s >= ms && cur_v >= mv)  
        {
            if (mn_c >= cur_c)
            {
                mn_c = cur_c;
                ret[mn_c].push_back(v);
            }
        }
    }
    
    if (mn_c == INF)
        cout << -1 << "\n";
    else
    {
        sort(ret[mn_c].begin(), ret[mn_c].end());
        cout << mn_c << "\n";
        for (int r : ret[mn_c][0])
            cout << r << " "; 
        cout << "\n";
    }

    
}