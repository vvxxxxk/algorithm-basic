#include <bits/stdc++.h>
using namespace std;

int ret;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = bandage[0]; // 시전 시간
    int x = bandage[1]; // 초당 회복량
    int y = bandage[2]; // 추가 회복량
    
    int current_time = 1;
    int success_streak = 0;
    int current_health = health;
    for (int i = 0; i < attacks.size(); i++)
    {
        int attack_time = attacks[i][0];
        int damage = attacks[i][1];
        for (current_time; current_time < attack_time; current_time++)
        {            
            current_health += x;    // 회복
            success_streak++;       // 연속 성공 +1
            
            // 연속 성공 횟수 도달 시 추가 회복
            if (success_streak == t)
            {
                current_health += y;
                success_streak = 0;
            }                
            
            // 현재 체력 > 최대체력
            if (current_health > health)
                current_health = health;
        }
        
        
        current_health -= damage;   // 공격
        success_streak = 0;         // 연속 성공 횟수 초기화
        current_time++;             // 시간 +1
        
        // 체력이 0 이하인 경우
        if (current_health <= 0)
            return -1;
        
        ret = current_health;
    }
    
    return ret;
}