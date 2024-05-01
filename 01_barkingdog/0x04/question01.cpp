/*
    https://www.acmicpc.net/problem/1406
*/
#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 초기 입력되어 있는 문자열
    string input;
    getline(cin, input);

    // 명령어 개수 입력
    int M;
    cin >> M;
    cin.ignore();

    // 명령어 입력
    string commands[M];
    for (int i = 0; i < M; i++)
        getline(cin, commands[i]);

    
    // 리스트 생성 및 input 데이터로 초기화
    list<char> texts;
    for (int i = 0; i < input.length(); i++)
        texts.push_back(input[i]);

    // 최초에 커서는 마지막 글자 오른쪽에 위치
    list<char>::iterator cursor = texts.end();  

    // 명령어 수행
    for(int i = 0; i < M; i++)
    {
        char command = commands[i][0];        

        if(command == 'L')
        {
            if(cursor != texts.begin())
                cursor--;
        }
        else if(command == 'D')
        {
            if(cursor != texts.end())
                cursor++;
        }
        else if(command == 'B')
        {
            if(cursor != texts.begin())
            {
                cursor--;
                cursor = texts.erase(cursor);
            }
        }
        else if(command == 'P')
        {
            texts.insert(cursor, commands[i][2]);
        }
    }

    // 출력
    for(char c : texts)
    {
        cout << c;
    }
    cout << "\n\n";
}