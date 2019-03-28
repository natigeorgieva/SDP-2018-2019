#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.sync();
    char*** matrix = new char**[n];

    for(int i = 0; i < n; i++){
        matrix[i] = new char*[n];
    }

    char word[31];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin.getline(word,31);
            matrix[i][j] = new char[strlen(word) + 1];
            strcpy(matrix[i][j], word);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(31) << matrix[j][i];
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            delete[] matrix[i][j];
        }
    }

    for(int j = 0; j < n; j++){
        delete[] matrix[j];
    }

    delete[] matrix;

    return 0;
}
