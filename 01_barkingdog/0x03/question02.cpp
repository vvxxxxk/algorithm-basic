#include <iostream>
#include <vector>
using namespace std;

int func(int arr[], int len)
{
    vector<int> numbers(101, 0);
    
    for (int i = 0; i < len; i++)
    {
        int x = 100 - arr[i];
        if(numbers[x] == 1)
            return 1;
        numbers[arr[i]] = 1;
    }

   return 0; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr1[3] = {1, 52, 48};
    int arr2[2] = {50, 42};
    int arr3[4] = {4, 13, 63, 87};
    int arr4[10] = {1, 2, 3, 50, 5, 6, 0, 7, 8, 9};

    int result1 = func(arr1, 3);
    int result2 = func(arr2, 2);
    int result3 = func(arr3, 4);
    int result4 = func(arr4, 10);

    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    cout << result4 << endl;
}