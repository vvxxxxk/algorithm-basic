#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum = 0;
vector<int> v(9);
vector<int> re;

void combination(int start, vector<int> v)
{
    if (re.size() == 2)
    {
        if (sum - re[0] - re[1] == 100)
        {
            for (int i : v)
            {
                if (i != re[0] && i != re[1])
                    cout << i << "\n";
            }

            exit(0);	// 경우의 수가 여러 개가 나타날 수 있어 정답 한 개만 출력 후 종료
        }
        
        return;
    }

    for (int i = start + 1; i < v.size(); i++)
    {
        re.push_back(v[i]);
        combination(i, v);
        re.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());
    combination(-1, v);
}