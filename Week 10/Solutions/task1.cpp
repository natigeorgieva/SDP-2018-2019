#include <iostream>
#include <queue>

using namespace std;

template <typename T>
T minElem(queue<T> q){

    T min = q.front();
    int qSize = q.size();
    T temp;
    for(int i = 0; i < qSize; i++){
        temp = q.front();
        if(temp < min){
            min = temp;
        }
        q.pop();
        q.push(temp);
    }
    return min;
}

int main(){
    queue<double> q;
    q.push(4.5);
    q.push(4.2);
    q.push(133);
    q.push(18);

    cout << minElem(q) << endl;




    return 0;
}
