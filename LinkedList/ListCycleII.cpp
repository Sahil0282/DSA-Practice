class Solution {
public:
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode* temp=head;
    //     unordered_map<ListNode*,int> freq;
    //     while(temp){
    //         if(freq.find(temp)!=freq.end()){
    //             return temp;
    //         }
    //         freq[temp]++;
    //         temp=temp->next;
    //     }
    //     return nullptr;
    // }
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                slow=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};