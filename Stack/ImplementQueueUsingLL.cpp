#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class LinkedListQueue {
public:
    Node* start;
    Node* end;
    LinkedListQueue() {
        start=end=nullptr;
    }
    
    void push(int x) {
        Node* newNode=new Node(x);
        if(start==nullptr){
            start=end=newNode;
        }
        else{
            end->next=newNode;
            end=newNode;
        }
    }
    
    int pop() {
        if(start!=nullptr){
            Node* temp=start;
            int retVal=temp->data;
            start=start->next;
            if(start==nullptr){
                end=nullptr;
            }
            delete temp;
            return retVal;
        }
        return -1;
    }
    
    int peek() {
        if(start!=nullptr) return start->data;
        return -1;
    }
    
    bool isEmpty() {
        return start==nullptr;
    }
    ~LinkedListQueue() {
        while (start != nullptr) {
            Node* temp = start;
            start = start->next;
            delete temp;
        }
    }
};
int main() {
    LinkedListQueue q;
    q.push(10);
    q.push(20);
    cout << q.peek() << endl; // Output: 10
    cout << q.pop() << endl;  // Output: 10
    cout << q.isEmpty() << endl; // Output: 0 (false)
    cout << q.pop() << endl;  // Output: 20
    cout << q.isEmpty() << endl; // Output: 1 (true)
    return 0;
}