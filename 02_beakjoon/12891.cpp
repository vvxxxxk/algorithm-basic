#include <bits/stdc++.h>
using namespace std;

int S, P;
int s_pos;
int ret;
string dna;
string pwd;
int mn_count_arr[4];
int cur_count_arr[4];

bool check()
{
    return (cur_count_arr[0] >= mn_count_arr[0]) && (cur_count_arr[1] >= mn_count_arr[1]) && 
           (cur_count_arr[2] >= mn_count_arr[2]) && (cur_count_arr[3] >= mn_count_arr[3]);
}

void add_counting(int idx)
{
    if (idx == 'A')
        cur_count_arr[0]++;
    if (idx == 'C')
        cur_count_arr[1]++;
    if (idx == 'G')
        cur_count_arr[2]++;
    if (idx == 'T')
        cur_count_arr[3]++;
}

void sub_counting(int idx)
{
    if (idx == 'A')
        cur_count_arr[0]--;
    if (idx == 'C')
        cur_count_arr[1]--;
    if (idx == 'G')
        cur_count_arr[2]--;
    if (idx == 'T')
        cur_count_arr[3]--;
}

void counting_print()
{
    cout << "A: " << cur_count_arr[0] << "\n";
    cout << "C: " << cur_count_arr[1] << "\n";
    cout << "G: " << cur_count_arr[2] << "\n";
    cout << "T: " << cur_count_arr[3] << "\n"; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> P >> dna;
    cin >> mn_count_arr[0] >> mn_count_arr[1] >> mn_count_arr[2] >> mn_count_arr[3];

    // 최초 pwd의 각 문자 개수 카운팅
    pwd = dna.substr(s_pos, P);
    for (int i = 0; i < pwd.size(); i++)
        add_counting(pwd[i]);

    // 최초 pwd가 조건에 일치하는 패스워드라면 ret + 1
    if (check())
        ret += 1;

    for (int i = P; i < S; i++)
    {
        sub_counting(dna[s_pos]);
        add_counting(dna[s_pos + P]);
        s_pos++;

        if (check())
            ret += 1;
    }
    
    cout << ret << "\n";
}