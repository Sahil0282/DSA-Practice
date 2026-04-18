// class Solution {
// public:
//     ListNode* reverseLL(ListNode* head){
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* newHead=reverseLL(head->next);
//         ListNode* front=head->next;
//         front->next=head;
//         head->next=nullptr;
//         return newHead;
//     }
//     ListNode *addOne(ListNode *head) {
//         head=reverseLL(head);
//         ListNode* temp=head;
//         ListNode* prev=nullptr;
//         int carry=1;
//         while(temp && carry==1){
//             int sum=temp->val+carry;
//             temp->val=sum%10;
//             carry=sum/10;
//             prev=temp;
//             temp=temp->next;
//         }
//         if(carry==1){
//             prev->next=new ListNode(1);
//         }
//         return reverseLL(head);
//     }
// };

class Solution {
public:
    int reverseLL(ListNode* head){
        if(head == NULL) return 1;
        int carry=reverseLL(head->next);
        head->val=head->val+carry;
        if(head->val<10){
            return 0;
        }else{
            head->val=0;
            return 1;
        }
        
    }
    ListNode *addOne(ListNode *head) {
        int carry=reverseLL(head);
        if(carry==1){
            ListNode* newNode=new ListNode(1);
            newNode->next=head;
            return newNode;
        }
        return head;
    }
};
