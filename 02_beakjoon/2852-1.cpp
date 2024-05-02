#include <bits/stdc++.h>
using namespace std;

int N;
int score1 = 0;
int score2 = 0;
string prev_score_time = "00:00";
string cur_score_time;
string winning_time1 = "00:00";
string winning_time2 = "00:00";

void getScoreTimeGap(string& winning_time, string prev_time, string cur_time) {
    int wt_mm = stoi(winning_time.substr(0, 2));
    int wt_ss = stoi(winning_time.substr(3, 2));
    int prev_mm = stoi(prev_time.substr(0, 2));
    int prev_ss = stoi(prev_time.substr(3, 2));
    int cur_mm = stoi(cur_time.substr(0, 2));
    int cur_ss = stoi(cur_time.substr(3, 2));

    int total_prev_seconds = prev_mm * 60 + prev_ss;
    int total_cur_seconds = cur_mm * 60 + cur_ss;
    int diff_seconds = total_cur_seconds - total_prev_seconds;

    wt_ss += diff_seconds % 60;
    wt_mm += diff_seconds / 60;
 
    if (wt_ss >= 60) {
        wt_ss -= 60;
        wt_mm += 1;
    }

    string ss = "00" + to_string(wt_ss);
    string mm = "00" + to_string(wt_mm);

    winning_time = mm.substr(mm.size()-2, 2) + ":" + ss.substr(ss.size()-2, 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while (N--) {
        int team_no;
        cin >> team_no >> cur_score_time;

        if (score1 > score2)    // 1번팀 점수가 높을 때
            getScoreTimeGap(winning_time1, prev_score_time, cur_score_time);
        if (score1 < score2)    // 2번팀 점수가 높을 때
            getScoreTimeGap(winning_time2, prev_score_time, cur_score_time);
 
        team_no == 1 ? score1++ : score2++;
 
        prev_score_time = cur_score_time;
    }
 
    if (score1 > score2)
        getScoreTimeGap(winning_time1, prev_score_time, "48:00");
    if (score1 < score2)
        getScoreTimeGap(winning_time2, prev_score_time, "48:00");

    cout << winning_time1 << "\n" << winning_time2 << "\n";
}