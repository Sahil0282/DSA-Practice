class Solution {
public:
    // ListNode* oddEvenList(ListNode* head) {
    //     if(!head || !head->next) return head;
    //     ListNode* temp=head;
    //     vector<int> odd;
    //     vector<int> evn;
    //     int count=0;
    //     while(temp){
    //         if(count%2==0) odd.push_back(temp->val);
    //         else evn.push_back(temp->val);
    //         count++;
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     for(int i=0;i<odd.size();i++){
    //         temp->val=odd[i];
    //         temp=temp->next;
    //     }
    //     for(int i=0;i<evn.size();i++){
    //         temp->val=evn[i];
    //         temp=temp->next;
    //     }
    //     return head;
    // }

    // ListNode* oddEvenList(ListNode* head) {
    //     if(!head || !head->next) return head;
    //     ListNode* odd=head;
    //     ListNode* even=head->next;
    //     ListNode* evenHead=even;
    //     while(even && even->next){
    //         odd->next=even->next;
    //         odd=odd->next;
    //         even->next=odd->next;
    //         even=even->next;
    //     }
    //     odd->next=evenHead;
    //     return head;
    // }

    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        vector<int> ans;
        while(temp && temp->next){
            ans.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)  ans.push_back(temp->val);
        temp=head->next;
        while(temp && temp->next){
            ans.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp) ans.push_back(temp->val);
        int index=0;
        temp=head;
        while(temp){
            temp->val=ans[index++];
            temp=temp->next;
        }
        return head;
    }
};