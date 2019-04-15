#include <iostream>
#include "Point3.h"

using namespace std;

void sortArr(Point3* arr, int n){
    int min;
    Point3 temp;
    for(int i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int n;
    cin >> n;

    Point3* points = new Point3[n];

    int x,y,z;
    ///Reading points
    for(int i = 0; i < n ; i++){
        cout << "Point " << i + 1 << ": " ;
        cin >> x >> y >> z;
        points[i] = Point3(x, y, z);
    }

    sortArr(points, n);

    cout << endl << "Printing sorted points" << endl;

    for(int i = 0; i < n; i++){
        cout << "Point " << i + 1 << ": " << points[i].getX() << " " << points[i].getY() << " " << points[i].getZ() << endl;
    }

    delete [] points; ///dont forget it!!!

    return 0;
}
