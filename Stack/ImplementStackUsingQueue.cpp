#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        //get the current size
        int s=q.size();
        //insert the elements ., which will be a last
        q.push(x);
        //move all other element i.e 0 till this element => after this element 
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl; // returns 2
    cout << st.pop() << endl; // returns 2
    cout << st.empty() << endl; // returns false
    return 0;
}