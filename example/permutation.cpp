#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(v.begin(), v.end());
    int cnt = 0;
    do
    {
        cnt++;
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    cout << "cnt: " << cnt << "\n";
}