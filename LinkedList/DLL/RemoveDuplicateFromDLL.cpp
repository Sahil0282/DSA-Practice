// #include<set>
// Node * removeDuplicates(Node *head)
// {
//     if(!head || !head->next) return head;
//     Node* temp=head;
//     set<int> st;
//     while(temp){
//         Node* front=temp->next;
//         if(st.find(temp->data)!=st.end()){
//             if(temp->prev) temp->prev->next=front;
//             if(front) front->prev=temp->prev;
//             delete temp;
//             temp=front;
//         }
//         else{
//             st.insert(temp->data);
//             temp=temp->next;
//         }
//     }
//     return head;
// };


#include<set>
Node * removeDuplicates(Node *head)
{
    if(!head || !head->next) return head;
    Node* temp=head;
    while(temp && temp->next){
        if(temp->data==temp->next->data){
            Node* dup=temp->next;
            temp->next=dup->next;
            if(dup->next) dup->next->prev=temp;
            delete dup;
        }else{
            temp=temp->next;
        }
    }
    return head;
};
