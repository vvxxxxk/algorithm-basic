#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {1, 0, 5};
    sort(v.begin(), v.end());

    do
    {
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    
}