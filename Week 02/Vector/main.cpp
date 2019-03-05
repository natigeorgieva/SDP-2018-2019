#include <iostream>

#include "vector.h"

using namespace std;

int main()
{
    const int N = 5;
    Vector arr[5];
    arr[0] = {1,4};
    arr[1] = Vector(3, 17);
    arr[2] = {6,6};
    arr[3] = {7,6};
    arr[4] = {6,0};


    double minLength;
    int minPosition;

    for (int i = 0; i < N - 1; i++)
    {
        minLength = arr[i].length();
        minPosition = i;
        for (int j = i + 1; j < N; j++)
        {
            double currentLength = arr[j].length();
            if(currentLength < minLength)
            {
                minLength = currentLength;
                minPosition = j;
            }
        }
        Vector temp = arr[i];
        arr[i] = arr[minPosition];
        arr[minPosition] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        arr[i].print();
    }



    return 0;
}
