/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        while(head && head->val==target){
            ListNode* temp=head;
            head=head->next;
            if(head) head->prev=NULL;
            delete temp;
        }
        ListNode* temp=head;
        while(temp){
            if(temp->val==target){
                ListNode* nextNode=temp->next;
                if(temp->prev) temp->prev->next=nextNode;
                if(nextNode) nextNode->prev=temp->prev;
                delete temp;
                temp=nextNode;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};