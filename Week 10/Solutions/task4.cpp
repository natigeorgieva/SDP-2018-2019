#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int minElem(queue<int>& q1, queue<int>& q2, queue<int>& q3)
{
    int elem1 = q1.front();
    int elem2 = q2.front();
    int elem3 = q3.front();
    if(elem1 < elem2 && elem1 < elem3)
    {
        q1.pop();
        q1.push(2 * elem1);
        q2.push(3 * elem1);
        q3.push(5 * elem1);
        return elem1;
    }
    if(elem2 < elem3)
    {
        q2.pop();
        q2.push(3 * elem2);
        q3.push(5 * elem2);
        return elem2;
    }
    q3.pop();
    q3.push(5 * elem3);
    return elem3;
}

void seq(int n)
{
    queue<int> q2;
    queue<int> q3;
    queue<int> q5;
    q2.push(2);
    q3.push(3);
    q5.push(5);

    int min;

    for(int counter = 0; counter < n; counter++)
    {
        cout << minElem(q2, q3, q5) << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    seq(n);


    return 0;
}
