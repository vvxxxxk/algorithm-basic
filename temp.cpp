#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
const int n = 3;
int a[3][3] = { {10, 20, 21}, 
                {70, 90, 12},
                {80, 110, 120} };
int visited[3][3];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
vector<int> v;

void print(){
	for(int i : v) 
        cout << i << " ";
	cout << "\n";
}

void dfs(int x, int y)
{
    if (x == n-1 && y == n-1)
    {
        print();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3 || visited[nx][ny] == 1)
            continue;
        
        visited[nx][ny] = 1;
        v.push_back(a[nx][ny]);

        dfs(nx, ny);

        visited[nx][ny] = 0;
        v.pop_back();
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    visited[0][0] = 1;
	v.push_back(a[0][0]);
	dfs(0, 0);  
    return 0;
}