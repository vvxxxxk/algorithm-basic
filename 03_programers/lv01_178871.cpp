#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<string, int> name_to_rank;
    map<int, string> rank_to_name;
    vector<string> answer;
    
    for (int i = 0; i < players.size(); i++)
    {
        name_to_rank[players[i]] = i+1;
        rank_to_name[i+1] = players[i];
    }
        
    
    for (string name : callings)
    {
        int target_rank = name_to_rank[name];
        string target_name = rank_to_name[target_rank];  
        int temp_rank = target_rank - 1;
        string temp_name = rank_to_name[temp_rank];
        
        rank_to_name[target_rank-1] = target_name;
        name_to_rank[target_name] = target_rank-1;
        rank_to_name[target_rank] = temp_name;
        name_to_rank[temp_name] = target_rank;
    }
    
    for (auto it = rank_to_name.begin(); it != rank_to_name.end(); it++)
        answer.push_back(it->second);
    
    return answer;
}