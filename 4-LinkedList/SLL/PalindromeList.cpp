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
    // brute force O(2n) TC and O(n) SC
    // bool isPalindrome(ListNode* head) {
    //     vector<int> ans;
    //     ListNode* temp=head;
    //     while(temp){
    //         ans.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     int l=0,r=ans.size()-1;
    //     while(l<r){
    //         if(ans[l]!=ans[r]) return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    // bool isPalindrome(ListNode* head) {
    //     stack<int> st;
    //     ListNode* temp=head;
    //     while(temp){
    //         st.push(temp->val);
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     while(temp){
    //         if(st.top()!=temp->val) return false;
    //         st.pop();
    //         temp=temp->next;
    //     }
    //     return true;
    // }
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* front=nullptr;
        ListNode* temp=head;
        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=reverseList(slow->next);

        ListNode* first=head;
        ListNode* second=newHead;
        while(second){
            if(first->val!=second->val){
                reverseList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(newHead);
        return true;
    }
};