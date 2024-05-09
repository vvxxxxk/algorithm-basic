#include <bits/stdc++.h>
using namespace std;

int k;
vector<char> comp_operations;
int visited[10];
vector<string> ret;

bool comp_check(char x, char y, char op)
{
    if(x < y && op == '<')
        return true; 
	if(x > y && op == '>')
        return true; 
	return false;
}

void go(int idx, string num){ 
	if(idx == k + 1)
    {	
	    ret.push_back(num);
        return;
	}
	for(int i = 0; i <= 9; i++){
		if (visited[i])
            continue; 
		if (idx == 0 || comp_check(num[idx - 1], i + '0', comp_operations[idx - 1])){
			visited[i] = 1;
			go(idx + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    char c;
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        comp_operations.push_back(c);
    }

    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}