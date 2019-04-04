#ifndef STACK_H
#define STACK_H


class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack&);
    const Stack& operator=(const Stack&);

    void pop();
    void push(int num);
    bool isEmpty()const;
    int length()const;
    int peek()const;




private:
    int *arr;
    int size;
    int capacity;

    void resizeUp();
    void resizeDown();
};

#endif // STACK_H
