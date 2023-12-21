#include <iostream>
#include <queue>
using namespace std;

// pair에서 first, second를 줄여서 쓰기 위해서 사용
#define X first
#define Y second 

// 1이 파란 칸, 0이 빨간 칸에 대응
int board[502][502] = {{1,1,1,0,1,0,0,0,0,0},
                       {1,0,0,0,1,0,0,0,0,0},
                       {1,1,1,0,1,0,0,0,0,0},
                       {1,1,0,0,1,0,0,0,0,0},
                       {0,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0}}; 

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수

// 상하좌우 네 방향을 의미
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int> > Q;

    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
  
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front(); 
        Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        
        // 상하좌우 칸을 살펴볼 것이다.
        for(int dir = 0; dir < 4; dir++)
        { 
            // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  // 범위 밖일 경우 넘어감
                continue; 

            if(vis[nx][ny] || board[nx][ny] != 1)       // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                continue; 

            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            
            Q.push({nx,ny});
        }
    }
}