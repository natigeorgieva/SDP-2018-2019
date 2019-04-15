#include "database.h"

#include <algorithm>
#include <iostream>

Database::Database()
{
    this->cards = new ISIC[2];
    this->size = 0;
    this->capacity = 2;
}

bool Database::isFull() const
{
    return (this->capacity - this->size) == 0;
}

bool Database::isEmpty() const
{
    return this->size == 0;
}

void Database::resizeUp()
{
    ISIC* newCards = new ISIC[2 * this->capacity];

    for(int i = 0; i < this->size; i++)
    {
        newCards[i] = cards[i];
    }

    delete[] this->cards;

    this->cards = newCards;

    this->capacity = 2 * this->capacity;
}

void Database::resizeDown()
{
    ISIC* newCards = new ISIC[this->capacity / 2];

    for(int i = 0; i < this->size; i++)
    {
        newCards[i] = cards[i];
    }

    delete[] this->cards;

    this->cards = newCards;

    this->capacity = this->capacity / 2;
}


void Database::add(const ISIC& card)
{
    if(this->isFull())
    {
        this->resizeUp();
    }

    this->cards[this->size] = card;

    this->size++;

}

void Database::remove(const char ID[17])
{
    if(!this->isEmpty())
    {
        int idx = -1;
        for(int i = 0; i < this->size; i++)
        {
            if(strcmp(this->cards[i].getID(), ID) == 0)
            {
                idx = i;
                break;
            }
        }
        if(idx != -1)
        {
            std::swap(this->cards[idx], this->cards[this->size - 1]);
            this->size--;
        }

        if((double)(this->size / this->capacity) - 0.25 < 0.00001)
            this->resizeDown();
    }
}

void Database::sortByNames()
{
    for(int i = 1; i < this->size; i++)
    {
        int k = i;
        while(k > 0 &&
                strcmp(this->cards[k].getName(), this->cards[k - 1].getName()) == -1)
        {
            swap(this->cards[k], this->cards[k - 1]);
            k--;
        }
    }
}

void Database::print() const
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->cards[i].getName() << " " << this->cards[i].getID() << std::endl;
    }
}

ISIC& Database::operator[](int n){
    return this->cards[n];
}

