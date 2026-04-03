class Solution {
public:
    // ListNode* sortList(ListNode* head) {
    //     if(!head || !head->next) return head;
    //     vector<int> ans;
    //     ListNode* temp=head;
    //     while(temp){
    //         ans.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     sort(ans.begin(),ans.end());
    //     int idx=0;
    //     temp=head;
    //     while(temp){
    //         temp->val=ans[idx++];
    //         temp=temp->next;
    //     }
    //     return head;
    // }
    ListNode* middleEle(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* t1=left;
        ListNode* t2=right;
        while(t1 && t2){
            if(t1->val<t2->val){
                temp->next=t1;
                temp=temp->next;
                t1=t1->next;
            }else{
                temp->next=t2;
                temp=temp->next;
                t2=t2->next;
            }
        }
        if(t1) temp->next=t1;
        if(t2) temp->next=t2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middle=middleEle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=nullptr;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};