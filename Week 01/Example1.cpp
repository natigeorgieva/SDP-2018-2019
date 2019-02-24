#include <iostream>
#include <string.h>

using namespace std;

///������: ������� ���� �� ���������, ���� ����, ��� ������ � �� ����� �� 2 �������
///������� �������������� �� ������� '#', ������ �� � ��� ����� � �� ��������.

const int WORD_SIZE = 31; ///������������ �� ������, ����� ��������� �� � �� ����� �� 30 �������

int main(){
    char word[WORD_SIZE];

    cin.getline(word, WORD_SIZE); ///������������ �� ����� � getline ���� ��������� <<
                                  ///,��� ���� � getline ����� �� ��������� ������� �� �����

    int wordLength = strlen(word); ///�������� ������ ������ �� ����������� ����

    ///����� ��� ����� ����� ���������� ������� � �� ������� (size - 1)

    if(wordLength > 2){
        word[wordLength - 2] = '#';
    }

    char wordCopy[WORD_SIZE]; ///������ �����, ����� �� ����������

    strcpy(wordCopy, word); ///���������� ����������

    if(!strcmp(word, wordCopy)){  ///����������� ���� ����� ���� �� ������� (��������� strcmp ����� �������� 0 ��� ������� ���������)
        cout << "Copy was successful!" << endl;
    } else {
        cout << "ERROR" << endl;
        return 0;
    }

    cout << wordCopy << endl; ///���������� �������


    return 0;
}
