#include <iostream>
using namespace std;

void insert(int idx, int num, int arr[], int& len)
{
    for(int i = len; i > idx; i--)
        arr[i] = arr[i-1];
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int& len)
{
    for(int i = idx; i < len - 1; i++)
        arr[i] = arr[i+1];
    len--;
}

void print_arr(int arr[], int& len)
{
    for(int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  print_arr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  print_arr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  print_arr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  print_arr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  print_arr(arr, len);
  erase(3, arr, len); // 10 40 30
  print_arr(arr, len);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    insert_test();
    erase_test();

    // 강의에서는 프로그래밍 언어 관점에서의 배열이 아닌 자료구조 관점에서의 배열로 생각
    // 프로그래밍 언어 관점에서의 배열은 원칙적으로 길이를 변경할 수 없으나, 자료구조 관점에서의 배열로 생각
    // 따라서, 아래 선언된 len 변수의 경우 배열의 크기를 의미하는 것이 아닌 길이를 의미. (최대 크기: 10, 길이: 6)
    int arr[10] = {10, 50, 40, 30, 70, 20}; 
    int len = 6;
                        
    cout << "***** main_test *****\n";
    insert(0, -1, arr, len);
    print_arr(arr, len);
    insert(3, 45, arr, len);
    print_arr(arr, len);
    erase(0, arr, len);
    print_arr(arr, len);
    erase(3, arr, len);
    print_arr(arr, len);

}