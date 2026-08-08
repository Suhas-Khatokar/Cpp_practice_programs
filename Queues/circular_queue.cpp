#include<iostream>
using namespace std;

class CircularQueue {
    int currSize;
    int f, r;
    int *arr;
    int cap;

    public:
    CircularQueue(int size) {
        cap = size;
        currSize = 0;
        f=0; r=-1;
        arr = new int[cap];
    }

    void push(int data) {
        if (cap == currSize) {
            cout<<"CQ is full"; 
            return;
        }
        r = (r+1)%cap; //To make the array circular
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (currSize == 0) {
            cout<<"CQ is empty"; 
            return;
        }
        f = (f+1)%cap;
        currSize--;
    }

    int front() {
        if (currSize == 0) {
            cout<<"CQ is empty"; 
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }
};


int main() {
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    //1 2 3
    cq.pop();
    //  2 3
    //  ^ ^
    //  f r

    cq.push(4);
    //4 2 3
    //^ ^
    //r f
    
    //But the queue is like 2 3 4
    while(!cq.empty()) {
        cout<<cq.front()<<" ";
        cq.pop();
    }
    return 0;
}