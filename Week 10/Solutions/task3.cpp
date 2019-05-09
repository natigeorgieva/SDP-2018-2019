#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void swapStacks(stack<stack<int>>& st1, stack<stack<int>>& st2){
    stack<int> temp;
    while(!st1.empty()){
        temp = st1.top();
        st1.pop();
        cout << temp.top() << " ";
        temp.pop();
        st2.push(temp);
    }
}

void snakePrint(queue<stack<int>>& q){
    stack<stack<int>> st1, st2;
    stack<int> temp;
    if(q.front().empty()) return;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp.top() << " ";
        temp.pop();
        st1.push(temp);
    }
    int step = 1;
    while(step % 2 == 0 ? !st2.top().empty() : !st1.top().empty()){
        if(step % 2 == 0){
            swapStacks(st2, st1);
        } else {
            swapStacks(st1, st2);
        }
        step++;
    }

}

int main(){
    stack<int> st1;
    stack<int> st2;
    stack<int> st3;
    stack<int> st4;
    st1.push(8);
    st2.push(7);
    st3.push(6);
    st4.push(5);
    st4.push(4);
    st3.push(3);
    st2.push(2);
    st1.push(1);
    queue<stack<int>> q;
    q.push(st1);
    q.push(st2);
    q.push(st3);
    q.push(st4);

    snakePrint(q);


    return 0;
}
