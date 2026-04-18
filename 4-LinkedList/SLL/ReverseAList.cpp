// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp=head;
//         vector<int> ans;
//         while(temp){
//             ans.push_back(temp->val);
//             temp=temp->next;
//         }
//         reverse(ans.begin(),ans.end());
//         temp=head;
//         int index=0;
//         while(temp){
//             temp->val=ans[index++];
//             temp=temp->next;
//         }
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp=head;
//         ListNode* prev=nullptr;
//         ListNode* front=nullptr;
//         while(temp){
//             front=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=front;
//         }
//         return prev;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
};
