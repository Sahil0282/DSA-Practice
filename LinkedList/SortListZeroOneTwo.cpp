class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
           ListNode* zeroHead=new ListNode(-1);
           ListNode* oneHead=new ListNode(-1);
           ListNode* twoHead=new ListNode(-1);
           ListNode* t1=zeroHead;
           ListNode* t2=oneHead;
           ListNode* t3=twoHead;
           ListNode* temp=head;
           while(temp){
            if(temp->data==0){
                t1->next=temp;
                t1=t1->next;
            }else if(temp->data==1){
                t2->next=temp;
                t2=t2->next;
            }else{
                t3->next=temp;
                t3=t3->next;               
            }
            temp=temp->next;
           }
           if(oneHead->next){
            t1->next=oneHead->next;
            t2->next=twoHead->next;
           }else{
            t1->next=twoHead->next;
           }
           t3->next = NULL;
           head=zeroHead->next;
           return head;
        }
};