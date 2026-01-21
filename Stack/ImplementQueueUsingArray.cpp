#include<iostream>
using namespace std;
class ArrayQueue {
public:
    int* QueueArr;
    int currSize,front,rear,cap;
    ArrayQueue() {
        cap=100;
        QueueArr=new int[cap];
        front=-1;
        rear=-1;
        currSize=0;
    }
    ~ArrayQueue(){
        delete[] QueueArr;
    }
    void push(int x) {
        if(currSize==cap)
        {
            cout<<"Queue is Full";
            return;
        }
        if(currSize==0){
            front=0;
            rear=0;
        }else{
            rear=(rear+1)%cap;
        }
        QueueArr[rear]=x;
        currSize+=1;
    }
    
    int pop() {
        if(front==-1){
            cout<<"Queue is empty";
            return -1;
        }
        int retElement=QueueArr[front];
        if(currSize==1){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%cap;
        }
        currSize-=1;
        return retElement;
    }
    
    int peek() {
        if(front==-1){
            cout<<"Queue is empty";
            return -1;
        }
        return QueueArr[front];
    }
    
    bool isEmpty() {
        return currSize==0;
    }
};
int main(){
    ArrayQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    return 0;
}