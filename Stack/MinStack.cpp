// class MinStack {
// public:
//     stack<pair<int,int>> st;
//     MinStack() {
//     }
//     void push(int val) {
//         if (st.empty()) {
//             st.push({val, val});
//         } else {
//             st.push({val, min(st.top().second, val)});
//         }
//     }
//     void pop() {
//         if(!st.empty()){
//             st.pop();
//         }
//     }
    
//     int top() {
//         if(!st.empty()){
//             return st.top().first;
//         }
//         return -1;
//     }
//     int getMin() {
//         if(!st.empty()){
//             return st.top().second;
//         }
//         return -1;
//     }
// };

#include<iostream>
#include<stack>
#include<string>
using namespace std;
class MinStack{
    stack<int> st, minSt;
public:
    MinStack(){
    }
    void push(int val){
        st.push(val);
        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
    }
    void pop(){
        if(st.empty()) return;
        if(st.top()==minSt.top()) minSt.pop();
        st.pop();
    }
    int top(){
        if(st.empty()) return -1;
        return st.top();
    }
    int getMin(){
        if(st.empty()) return -1;
        return minSt.top();
    }
};
int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;        // Returns 0
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -2
    return 0;
}