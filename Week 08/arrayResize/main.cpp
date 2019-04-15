#include <iostream>

using namespace std;

int main()
{
    ///Doubling correctly the size of dynamic array

    int n;
    cin >> n;

    int *arr = new int[n](); /// () fills the array with zeros
    arr[n - 1] = 6;

    int *arrDoubled = new int[2 * n]();
    for(int i = 0 ; i < n ; i++)
    {
        arrDoubled[i] = arr[i];
    }

    delete [] arr;

    arr = arrDoubled;

    arr[n*2 - 1] = 12;

    for(int i = 0 ; i < 2 * n ; i++)
    {
        cout << arr[i] << endl;
    }

    delete [] arr; ///Don`t forget this!!!

    return 0;
}
