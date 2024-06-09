#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<string, int> gift_count;
    map<string, int> next_gift_count;
    map<string, int> gift_points;
    
    // 선물지수 초기화
    // 다음달 선물 개수 초기화
    for (string s : friends)
    {
        gift_points[s] = 0;
        next_gift_count[s] = 0;
    }
        
    for (string s : gifts)
    {
        // 선물지수
        string sender = s.substr(0, s.find(" "));
        string receiver = s.substr(s.find(" ")+1);   
        gift_points[sender] += 1;    // 준 선물일 경우 선물지수 +1
        gift_points[receiver] -= 1;  // 받은 선물인 경우 선물지수 -1
        
        // 주고받은 선물
        if (gift_count.find(s) == gift_count.end())
            gift_count[s] = 1;
        else
            gift_count[s] += 1;
    }
    
    // 다음달 선물 개수
    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i+1; j < friends.size(); j++)
        {
            string key1 = friends[i]+ " " + friends[j];
            string key2 = friends[j]+ " " + friends[i];
            
            // 두 사람이 선물을 주고받지 않았거나 같은 경우
            if ((gift_count[key1] == 0 && gift_count[key2] == 0) || (gift_count[key1] == gift_count[key2]))
            {
                // 선물지수 비교
                // 선물지수가 큰 사람은 다음달에 선물을 한 개 받는다.
                if (gift_points[friends[i]] > gift_points[friends[j]])
                    next_gift_count[friends[i]] += 1;
                else if (gift_points[friends[j]] > gift_points[friends[i]])
                    next_gift_count[friends[j]] += 1;
            }
            
            // 두 사람 중 더 많은 선물을 준 사람은 다음달에 선물을 하나 받는다.
            if (gift_count[key1] > gift_count[key2])
                next_gift_count[friends[i]] += 1;
            else if (gift_count[key1] < gift_count[key2])
                next_gift_count[friends[j]] += 1;
        }
    }
    
    int mx = -1;
    for (string s : friends)
    {
        if (mx < next_gift_count[s])
            mx = next_gift_count[s];
    }
    
    return mx;
}