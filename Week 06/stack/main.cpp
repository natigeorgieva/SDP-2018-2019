#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack a;
    a.push(24);
    a.push(4);
    a.push(44);
    a.push(64);
    a.push(48);

    cout << a.peek() << endl;
    a.pop();

    cout << a.peek() << endl;
    a.pop();

    a.push(111);

    cout << a.peek() << endl;
    a.pop();

    cout << a.peek() << endl;
    a.pop();

    cout << a.peek() << endl;
    a.pop();

    cout << a.peek() << endl;
    a.pop();

    return 0;
}
