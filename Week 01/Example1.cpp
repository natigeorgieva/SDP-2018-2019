#include <iostream>
#include <string.h>

using namespace std;

///Задача: Прочита дума от конзолата, след това, ако думата е по дълга от 2 символа
///променя предпоследният на символа '#', копира го в нов масив и го принтира.

const int WORD_SIZE = 31; ///предполагаме че думата, която прочитаме не е по дълга от 30 символа

int main(){
    char word[WORD_SIZE];

    cin.getline(word, WORD_SIZE); ///предпочитаме да четем с getline пред оператора <<
                                  ///,тъй като с getline можем да ограничим размера на входа

    int wordLength = strlen(word); ///намираме точния размер на прочетената дума

    ///както във всеки масив последният елемент е на позиция (size - 1)

    if(wordLength > 2){
        word[wordLength - 2] = '#';
    }

    char wordCopy[WORD_SIZE]; ///правим копие, което ще принтираме

    strcpy(wordCopy, word); ///извършваме копирането

    if(!strcmp(word, wordCopy)){  ///проверяваме дали двете думи са еднакви (функцията strcmp връща стойност 0 при еднакви аргументи)
        cout << "Copy was successful!" << endl;
    } else {
        cout << "ERROR" << endl;
        return 0;
    }

    cout << wordCopy << endl; ///принтираме копието


    return 0;
}
