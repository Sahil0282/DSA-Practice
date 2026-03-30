/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* deleteMiddle(ListNode* head) {
    //     if(!head || !head->next) return NULL;
    //     int count=0;
    //     ListNode* temp=head;
    //     while(temp){
    //         count++;
    //         temp=temp->next;
    //     }
    //     int index=count/2;
    //     temp=head;
    //     count=0;
    //     while(temp){
    //         count++;
    //         if(count==index) break;
    //         temp=temp->next;
    //     }  
    //     temp->next=temp->next->next;      
    //     return head;
    // }

    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return head;
    }
};