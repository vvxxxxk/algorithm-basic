#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    map<int, string> number_key_map;
    map<string, int> name_key_map;
    for (int i = 1; i <= n; i++)
    {
        string name;
        cin >> name;
        number_key_map[i] = name;
        name_key_map[name] = i;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
    
        // 영문이 주어졌을 경우
        if (name_key_map.find(s) != name_key_map.end())
        {
            cout << name_key_map[s] << "\n";
        }
        else
        {
            int number_key = stoi(s);
            cout << number_key_map[number_key] << "\n";
        }
    }
}