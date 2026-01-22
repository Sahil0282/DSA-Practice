#include<iostream>
#include<stack>
using namespace std;
// class MyQueue {
// public:
//     stack<int> s1,s2;
//     MyQueue() {    
//     }
//     void push(int x) {
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
    
//     int pop() {
//         if(!s1.empty()){
//             int ret=s1.top();
//             s1.pop();
//             return ret;
//         }
//         return -1;
//     }
    
//     int peek() {
//         if(!s1.empty()){
//             return s1.top();
//         }
//         return -1;
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {    
    }
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int val=s2.top();
            s2.pop();
            return val;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int val=s2.top();
            s2.pop();
            return val;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout<<obj->peek()<<endl; // return 1
    cout<<obj->pop()<<endl; // return 1
    cout<<obj->empty()<<endl; // return false
    return 0;
}