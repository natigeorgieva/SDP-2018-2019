#ifndef DATABASE_H
#define DATABASE_H

#include "isic.h"

class Database
{
public:
    Database();
    bool isEmpty() const;
    bool isFull() const;

    void add(const ISIC& card);
    void remove(const char ID[17]);
    void sortByNames();
    void print() const;
    ISIC& operator[](int);

private:
    ISIC* cards;
    int size;
    int capacity;

    void resizeUp();
    void resizeDown();
};

#endif // DATABASE_H
