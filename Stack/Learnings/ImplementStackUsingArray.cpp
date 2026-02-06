#include<iostream>
using namespace std;
class ArrayStack {
public:
    int capacity;
    int* stackArray;
    int topIndex;
    ArrayStack(int size=1000) {
        capacity=size;//initlize the capacity of stack 
        stackArray =new int[capacity]; //initlize the dynamic array
        topIndex=-1;  
    }
    ~ArrayStack() {
        delete[] stackArray;
    }   
    
    void push(int x) {
        if(topIndex>=capacity-1){
            cout<<"Stack Overflow";
            return;
        }
        stackArray[++topIndex]=x;
    }
    
    int pop() {
        if(topIndex==-1){
            cout<<"Stack Underflow";
            return -1;
        }
        return stackArray[topIndex--];

    }
    
    int top() {
        if(topIndex==-1){
            cout<<"Stack Underflow";
            return -1;
        }
        return stackArray[topIndex];
    }
    
    bool isEmpty() {
        if(topIndex==-1){
            return true;
        }
        return false;
    };
};
int main() {
    ArrayStack stack(5);
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.top() << endl; // Output: 20
    cout << "Popped element: " << stack.pop() << endl; // Output: 20
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: No
    return 0;
}