class Solution {
public:
    // //Brute force approch TC O(n) and SC(n log n)
    // bool hasCycle(ListNode *head) {
    //     if(!head || !head->next) return false;
    //     ListNode* temp=head;
    //     unordered_map<ListNode*,int> freq;
    //     while(temp){
    //         if(freq.find(temp)!=freq.end()){
    //             return true;
    //         }
    //         freq[temp]++;
    //         temp=temp->next;
    //     }
    //     return false;
    // }
    //optimal solution TC O(n) and SC O(1);
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};