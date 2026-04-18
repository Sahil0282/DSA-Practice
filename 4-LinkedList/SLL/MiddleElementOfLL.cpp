// //Brute Force O(2n)
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* temp=head;
//         int count=0;
//         while(temp){
//             count++;
//             temp=temp->next;
//         }
//         int index=(count/2)+1;
//         temp=head;
//         count=0;
//         while(temp){
//             count++;
//             if(count==index) return temp;
//             temp=temp->next;
//         }
//         return temp; 
//     }
// };

//Optimal Solution O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};