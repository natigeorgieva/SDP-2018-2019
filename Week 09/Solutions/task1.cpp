#include <iostream>

#include <stack>

using namespace std;

bool isSumCorrect(stack<int> st, int a, int b){
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    return sum >= a && sum <= b;
}

void findIndexes(stack<stack<int>> st, int a, int b){
    int counter = 1;
    while(!st.empty()){
        stack<int> temp = st.top();
        st.pop();
        if(isSumCorrect(temp, a, b)){
            cout << counter << endl;
        }
        counter++;
    }
}

int main(){
    stack<stack<int>> st;
    stack<int> st1;
    st1.push(3);
    st1.push(6);
    st1.push(10);
    st1.push(8);
    st1.push(3);
    st.push(st1);

    stack<int> st2;
    st2.push(1);
    st2.push(-8);
    st2.push(0);
    st2.push(1);
    st2.push(1);
    st.push(st2);

    findIndexes(st, -2, 31);

    return 0;
}
