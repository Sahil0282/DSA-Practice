// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(!headA || !headB) return NULL;
//         ListNode* tempA=headA;
//         ListNode* tempB=headB;
//         while(tempA!=tempB){
//             tempA=(tempA==NULL)?headB:tempA->next;
//             tempB=(tempB==NULL)?headA:tempB->next;
//         }
//         return tempA;
//     }
// };

// class Solution {
// public:
//     ListNode* intersection(ListNode* tempA,ListNode* headB){
//         ListNode* tempB=headB;
//         while(tempB){
//             if(tempB==tempA) return tempB;
//             tempB=tempB->next;
//         }
//         return NULL;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* tempA=headA;
//         while(tempA){
//             ListNode* ans=intersection(tempA,headB);
//             if(ans) return ans;
//             tempA=tempA->next;
//         }
//         return NULL;
//     }
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        unordered_map<ListNode*,int> mp;
        while(tempA){
            mp[tempA]++;
            tempA=tempA->next;
        }
        while(tempB){
            if(mp.find(tempB)!=mp.end()) return tempB;
            tempB=tempB->next;
        }
        return NULL;
    }
};