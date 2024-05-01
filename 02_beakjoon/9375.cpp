#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        
        map<string, int> mp;
        for (int j = 0; j < n; j++)
        {
            string name, type;
            cin >> name >> type;

            mp[type]++;
        }

        int count = 1;
        auto m_it = mp.begin();
        for (; m_it != mp.end(); m_it++)
            count *= (m_it->second + 1);
        
        cout << count - 1 << "\n";
    }    
}