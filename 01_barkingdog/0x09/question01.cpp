/*
 * https://www.acmicpc.net/problem/1926
 */
#include <iostream>
#include <queue>
using namespace std;

// pair에서 first, second를 줄여서 쓰기 위해서 사용
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int picture_count = 0;
    int picture_max_area = 0;

    int n, m;
    cin >> n >> m;

    int paper[n][m];
    bool is_visit[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            paper[i][j] = temp;
            is_visit[i][j] = false;
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // BFS 시작점 가능 여부 판단
            if (paper[i][j] == 1 && is_visit[i][j] == false)
            {
                int area = 0;           // BFS 시작 전 넓이 변수 초기화
                picture_count++;        // BFS 1회 == 그림 1개
                is_visit[i][j] = true;
                q.push({i, j});

                while(!q.empty())
                {
                    pair<int, int> point = q.front();
                    q.pop();
                    area++;
                
                    // 현재 point의 상하좌우 칸 확인
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int near_x = point.X + dx[dir];
                        int near_y = point.Y + dy[dir];

                        if (near_x < 0 || near_x >= n || near_y < 0 || near_y >= m)
                            continue;

                        if (is_visit[near_x][near_y] == true || paper[near_x][near_y] == 0)
                            continue;
                        
                        is_visit[near_x][near_y] = true;
                        q.push({near_x, near_y});
                    }
                }
                if (area > picture_max_area)
                    picture_max_area = area;
            }   

        }
    }
    
    cout << picture_count << "\n";
    cout << picture_max_area << "\n";

}