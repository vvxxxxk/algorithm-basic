#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int r, c;
    cin >> r >> c;
    vector<string> boards(r);
    queue<pair<int, int>> f_queue;
    queue<pair<int, int>> j_quque;
    int f_dist[r][c];
    int j_dist[r][c];

    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j]-'#' == 0)
            {
                f_dist[i][j] = -1;
                j_dist[i][j] = -1;
            }
            else if (s[j]-'J' == 0)
            {
                j_quque.push({i, j});
                j_dist[i][j] = 1;
                f_dist[i][j] = 0;
            }
            else if (s[j]-'F' == 0)
            {
                f_queue.push({i, j});
                f_dist[i][j] = 1;
                j_dist[i][j] = -1;
            }
            else if (s[j]-'.' == 0)
            {
                f_dist[i][j] = 0;
                j_dist[i][j] = 0;
            }
        }
    }

    while (!f_queue.empty())
    {
        pair<int, int> point = f_queue.front();
        f_queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int near_x = point.first + dx[i];
            int near_y = point.second + dy[i];

            if (near_x < 0 || near_x >= r || near_y < 0 || near_y >= c)
                continue;
            if (f_dist[near_x][near_y] != 0)
                continue;
            
            f_queue.push({near_x, near_y});
            f_dist[near_x][near_y] = f_dist[point.first][point.second] + 1;
        }
    }

    // cout << "-------------------------" << "\n";
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << f_dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "-------------------------" << "\n";

    int min_escape_time = 9999;

    while (!j_quque.empty())
    {
        pair<int, int> point = j_quque.front();
        j_quque.pop();

        if (point.first == 0 || point.first == r - 1 || point.second == 0 || point.second == c - 1)
        {
            if (j_dist[point.first][point.second] != -1 && j_dist[point.first][point.second] < min_escape_time)
                min_escape_time = j_dist[point.first][point.second];
        }

        for (int i = 0; i < 4; i++)
        {
            int near_x = point.first + dx[i];
            int near_y = point.second + dy[i];

            if (near_x < 0 || near_x >= r || near_y < 0 || near_y >= c)
                continue;
            if (j_dist[near_x][near_y] != 0 || j_dist[point.first][point.second] == -1)
                continue;
            
            j_quque.push({near_x, near_y});
            j_dist[near_x][near_y] = j_dist[point.first][point.second] + 1;
            
            if (j_dist[near_x][near_y] >= f_dist[near_x][near_y] && f_dist[near_x][near_y] != 0)
            {
                j_dist[near_x][near_y] = -1;
                continue;
            }
            if (near_x == 0 || near_x == r - 1 || near_y == 0 || near_y == c - 1)
            {
                if (j_dist[near_x][near_y] < min_escape_time)
                    min_escape_time = j_dist[near_x][near_y];

                // cout << "j_dist[near_x][near_y]: " << j_dist[near_x][near_y] << "\n";
                // cout << "min_escape_time: " << min_escape_time << "\n";
            }
        }
    }

    // cout << "========================" << "\n";
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << j_dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "========================" << "\n";

    if (min_escape_time == 9999)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << min_escape_time << "\n";
}