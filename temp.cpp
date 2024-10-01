#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, vector<string> delimiters)
{
    vector<string> ret;
    while(true)
    {
        size_t pos = string::npos;
        string token = "";
        int delimiter_length = 0;
        for (int i = 0; i < delimiters.size(); i++)
        {
            size_t temp_pos = input.find(delimiters[i]);
            if (temp_pos != string::npos && (pos == string::npos || temp_pos < pos))
            {
                pos = temp_pos;
                delimiter_length = delimiters[i].length();
            }
        }

        if (pos == string::npos)
            break;

        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter_length);
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str = "abc,def,ghi,jkl..mno..pqr..stu-vwx-yz";
    vector<string> delimiters = {",", "..", "-"};
    vector<string> v = split(str, delimiters);

    cout << "split 전: " << str << "\n";
    cout << "split 후: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << "\n";
}