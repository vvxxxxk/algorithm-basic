    #include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<string, set<string>> reporting_logs;
    map<string, set<string>> reported_logs;
    vector<int> answer(id_list.size(), 0);
    
    for (string s : report)
    {
        string reporting_user = s.substr(0, s.find(" "));   // 신고한 유저
        string reported_user = s.substr(s.find(" ")+1);     // 신고당한 유저
        
        reporting_logs[reporting_user].insert(reported_user);
        reported_logs[reported_user].insert(reporting_user);
    }
    
    for (int i = 0; i < id_list.size(); i++)
    {
        string reporting_user = id_list[i];
        
        for (const string& reported_user : reporting_logs[reporting_user])
        {
            // 신고 기록이 k 이상일 때
            if (k <= reported_logs[reported_user].size())
                answer[i] += 1;
        }
    }
    
    return answer;
}