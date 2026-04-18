#include<iostream>
using namespace std;
class LinkedListStack {
public:
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=nullptr;
        }
    };
    Node* head;
    LinkedListStack() {
        head=nullptr;
    }
    
    void push(int x) {
        Node* newNode=new Node(x);
        newNode->next=head;
        head=newNode;
    }
    
    int pop() {
        if (head == nullptr) return -1;
        Node* temp=head;
        head=head->next;
        int retVal=temp->data;
        delete temp;
        return retVal;
    }
    
    int top() {
        if(head!=nullptr) return head->data;
        return -1;
    }
    
    bool isEmpty() {
        return head==nullptr;
    }
};
int main() {
    LinkedListStack stack;
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.top() << endl; // Output: 20
    cout << "Popped element: " << stack.pop() << endl; // Output: 20
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: No
    cout << "Popped element: " << stack.pop() << endl; // Output: 10
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Yes
    return 0;
}