class Solution {
public:
    // int findLengthOfLoop(ListNode *head) {
    //     ListNode* temp=head;
    //     unordered_map<ListNode*,int> freq;
    //     while(temp){
    //         if(freq.find(temp)!=freq.end()){
    //             int count=1;
    //             ListNode* ptr=temp->next;
    //             while(ptr!=temp){
    //                 count++;
    //                 ptr=ptr->next;
    //             }
    //             return count;
    //         }
    //         freq[temp]++;
    //         temp=temp->next;
    //     }
    //     return 0;
    // }
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                slow=slow->next;
                int count=1;
                while(fast!=slow){
                    slow=slow->next;
                    count++;
                }   
                return count;
            }
        }
        return 0;
    }
};