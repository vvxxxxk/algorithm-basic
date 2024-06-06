#include <bits/stdc++.h>
using namespace std;

void input_func();

const int INF = 987654321;

int n;
vector<int> p_cnt(10);
vector<vector<int>> area_info(10);
vector<int> v;
vector<bool> visited(10);

int mn = INF;

void dfs(int start, vector<int> &area)
{
    visited[start] = 1;

    for (int adj_idx : area_info[start])
    {
        if (visited[adj_idx])
            continue;
        if (find(area.begin(), area.end(), adj_idx) != area.end())
            dfs(adj_idx, area);
    }
}

bool check_area()
{
    vector<int> first_area;
    vector<int> second_area;

    // 첫 번째 구역 목록, 두 번째 구역 목록 초기화
    for (int i = 0; i < n; i++)
    {
        // v에 포함되면 첫 번째 구역, 포함되지 않았다면 두 번째 구역으로 초기화
        if (find(v.begin(), v.end(), i) != v.end())
            first_area.push_back(i);
        else
            second_area.push_back(i);
    }

    // 첫 번째 구역이 조건과 일치하는 지 확인 (connected component 체크)
    fill(visited.begin(), visited.end(), false);
    dfs(first_area[0], first_area);
    bool is_first_connected_component = true;
    for (int idx : first_area)
    {
        if (!visited[idx])
            is_first_connected_component = false;
    }

    // 두 번째 구역이 조건과 일치하는 지 확인 (connected component 체크)
    fill(visited.begin(), visited.end(), false);
    dfs(second_area[0], second_area);
    bool is_second_connected_component = true;
    for (int idx : second_area)
    {
        if (!visited[idx])
            is_second_connected_component = false;
    }

    // cout << "is_f: " << is_first_connected_component  << ", is_s: " << is_second_connected_component << "\n";
    if (is_first_connected_component && is_second_connected_component)
    {
        // 3. 인구수의 최솟값을 갱신한다.
        int first_sum = 0;
        for (int a : first_area)
            first_sum += p_cnt[a];
        int second_sum = 0;
        for (int a : second_area)
            second_sum += p_cnt[a];

        mn = min(mn, abs(first_sum - second_sum));
        return true;
    }
    else
        return false;
}

void combi(int idx, int size)
{
    // size만큼의 조합이 포함된 경우
    if (v.size() == size)
    {
        // 2. 구역이 2개로 나누어졌는 지 체크한다.
        //  - v에 담긴 구역이 하나인지 체크
        //  - v에 담기지 않은 구역들이 하나인지 체크
        bool is_connected_component = check_area();
        return;
    }

    for (int i = idx; i < n; i++)
    {
        v.push_back(i);
        combi(i+1, size);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    input_func();

    for (int i = 1; i < n; i++)
    {
        // 1. 조합을 통해서 구역을 나눈다.
        combi(0, i);
    }

    if (mn == INF)
        cout << -1 << "\n";
    else
        cout << mn << "\n";
}

void input_func()
{
    // 구역 개수 입력
    cin >> n;
    
    // 구역 별 인구수 입력
    for (int i = 0; i < n; i++)
        cin >> p_cnt[i];

    // [인접 구역 수, 인접 구역 번호 ...] 입력
    int adj_area_cnt;
    int adj_area_no;
    for (int i = 0; i < n; i++)
    {
        cin >> adj_area_cnt;
        for (int j = 0; j < adj_area_cnt; j++)
        {
            cin >> adj_area_no;
            area_info[i].push_back(adj_area_no-1);
        }
    }
}