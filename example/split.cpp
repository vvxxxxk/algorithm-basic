#include <iostream>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    string str = "안 녕 하 세요 !";
    string d = " ";
    vector<string> str_v = split(str, d);

    for (string s : str_v)
        cout << s << "\n";
}