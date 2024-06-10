#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> answer;
    
    // 시작 좌표 초기화
    int start_x, start_y;
    for (int i = 0; i < park.size(); i++)
    {
        if (park[i].find("S") != string::npos)
        {
            start_x = i;
            start_y = park[i].find("S");
        }
    }
    
    for (int i = 0; i < routes.size(); i++)
    {
        char direction = routes[i][0];
        int distance = stoi(routes[i].substr(1));
        
        int next_x = start_x;
        int next_y = start_y;
        
        if (direction == 'N')
            next_x -= distance; 
        else if (direction == 'S')
            next_x += distance;
        else if (direction == 'E')
            next_y += distance;
        else if (direction == 'W')
            next_y -= distance;
        
        // 공원을 벗어난 경우 체크
        if (next_x < 0 || next_x >= park.size() || next_y < 0 || next_y >= park[0].size())
            continue;
        
        // 장애물을 만난 경우 체크
        bool flag = false;
        for (int j = 1; j <= distance; j++)
        {
            if (direction == 'N')
            {
                if (park[start_x-j][start_y] == 'X')
                    flag = true;
            }
            else if (direction == 'S')
            {
                if (park[start_x+j][start_y] == 'X')
                    flag = true;
            }
            else if (direction == 'E')
            {
                if (park[start_x][start_y+j] == 'X')
                    flag = true;
            }
            else if (direction == 'W')
            {
                if (park[start_x][start_y-j] == 'X')
                    flag = true;
            }
        }
        
        if (flag)
            continue;
        
        
        start_x = next_x;
        start_y = next_y;
    }
    
    answer.push_back(start_x);
    answer.push_back(start_y);
    return answer;
}