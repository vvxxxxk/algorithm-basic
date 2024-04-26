#include <iostream>

using namespace std;

int n = 5;
int k = 3;

void print(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << "\n";
}

void combi(int start, vector<int> v)
{
    if (v.size() == k)
    {
        // logic
        print(v);

        return ;
    }

    for (int i = start + 1; i < n; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    vector<int> v;
    combi(-1, v);
}