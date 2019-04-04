#include "stack.h"
#include <cassert>

Stack::Stack()
{
    capacity = 1;
    size = 0;
    arr = new int [capacity];
}

Stack::~Stack()
{
    delete []arr;
}

Stack::Stack(const Stack& stack1)
{
    this->arr = new int [capacity];

    for(int i=0; i<stack1.size; i++)
    {
        this->arr[i]=stack1.arr[i];
    }

    this->capacity =stack1.capacity;
    this->size=stack1.size;
}

const Stack& Stack::operator=(const Stack& stack1)
{

    if(this!=&stack1)
    {
        delete [] this->arr;

        this->arr = new int [capacity];

        for(int i=0; i<stack1.size; i++)
        {
            this->arr[i]=stack1.arr[i];
        }

        this->capacity =stack1.capacity;
        this->size=stack1.size;

    }
    return *this;
}

void Stack::resizeUp()
{
    int* newArray = new int[this->capacity * 2];
    for(int i = 0; i < this->size; i++)
    {
        newArray[i] = this->arr[i];
    }

    delete [] this->arr;

    this->arr = newArray;
}

void Stack::resizeDown()
{
    int* newArray = new int[this->capacity / 2];
    for(int i = 0; i < this->size; i++)
    {
        newArray[i] = this->arr[i];
    }

    delete [] this->arr;

    this->arr = newArray;
}

void Stack::pop()
{
    assert(!isEmpty());

    this->size--;

    if(this->size < this->capacity / 4){
        this->resizeDown();
    }

}

void Stack::push(int num)
{
    if(this->size == this->capacity){
        this->resizeUp();
    }

    this->arr[this->size] = num;
    this->size++;
}

bool Stack::isEmpty()const
{
    return size == 0;
}

int Stack::length()const
{
    return size;
}

int Stack::peek()const
{
    assert(!isEmpty());

    return  arr[size-1];

}
