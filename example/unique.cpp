#include <iostream>

using namespace std;

int main()
{
    vector<int> v{1, 1, 2, 2, 3, 3};

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i : v)
        cout << i << "\n";
    
    return 0;
}