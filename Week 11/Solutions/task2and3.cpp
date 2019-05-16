#include <iostream>
#include "llist.h"

using namespace std;

template <typename T>
bool containsNotRec(LList<T> lst, T elem){
    lst.iterStart();
    elem_link1<T>* it = lst.iter();
    while(it){
        if(it->inf == elem){
            return true;
        }
        it = it->link;
    }
    return false;
}

template <typename T>
bool containsNotRec2(LList<T> lst, T elem){
    lst.iterStart();
    elem_link1<T>* it = lst.iter();
    while(it){
        if(it->inf == elem){
            return true;
        }
        it = lst.iter();
    }
    return false;
}

template <typename T>
bool containsHelper(LList<T>& lst, const T& elem){
    elem_link1<T>* it = lst.iter();
    if(elem == it->inf){
        return true;
    }
    if(!it->link){
        return false;
    }
    return containsHelper(lst, elem);
}

template <typename T>
bool contains(LList<T>& lst, const T& elem){
    lst.iterStart();
    return containsHelper(lst, elem);
}

template <typename T>
bool containsSame(LList<T>& lst){
    lst.iterStart();
    elem_link1<T>* it = lst.iter();
    elem_link1<T>* it2;
    while(it){
        it2 = it->link;
        while(it2){
            if(it->inf == it2->inf){
                return true;
            }

            it2 = it2->link;
        }
        it = it->link;
    }
    return false;
}

int main()
{
    LList

    return 0;
}
