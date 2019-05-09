#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> mergeQs(queue<int>& q1, queue<int>& q2)
{
    queue<int> q3;
    int temp;
    while(!q1.empty() && !q2.empty())
    {
        if(q1.front() > q2.front())
        {
            temp = q2.front();
            q2.pop();
            q3.push(temp);
        }
        else
        {
            temp = q1.front();
            q1.pop();
            q3.push(temp);
        }
    }

    if(q1.empty())
    {
        while(!q2.empty())
        {
            q3.push(q2.front());
            q2.pop();
        }
    } else {
        while(!q1.empty())
        {
            q3.push(q1.front());
            q1.pop();
        }
    }

    return q3;
}

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

int main()
{

    queue<int> q1;
    queue<int> q2;
    q1.push(-4);
    q1.push(-1);
    q1.push(11);
    q1.push(25);
    q1.push(27);
    q1.push(36);

    q2.push(0);
    q2.push(11);
    q2.push(12);
    q2.push(27);

    print(mergeQs(q1, q2));



    return 0;
}
