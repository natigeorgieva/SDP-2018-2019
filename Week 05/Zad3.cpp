#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int** triangle = new int*[n];
    for(int i = 0; i < n; i++){
        triangle[i] = new int[n - i];
        for(int j = 0; j < n - i; j++){
            cin >> triangle[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << setw(4) << triangle[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}
