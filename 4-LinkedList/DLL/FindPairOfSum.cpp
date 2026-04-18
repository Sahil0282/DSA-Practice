// class Solution {
// public:
//     vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
//         vector<vector<int>> res;
//         ListNode* temp=head;
//         unordered_set<int> st;
//         while(temp){
//             int no=temp->val;
//             int rem=target-no;
//             if(st.find(rem)!=st.end()){
//                 res.push_back({rem,no});
//             }
//             st.insert(no);
//             temp = temp->next;
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;
        ListNode* right=head;
        ListNode* left=head;
        while(right->next){
            right=right->next;
        }
        //    valid && valid && also valid && but why this
        while(left && right && right!=left && right->prev!=left){
            int sum=left->val+right->val;
            if(sum==target){
                ans.push_back({left->val,right->val});
                right=right->prev;
                left=left->next;
            }
            else if(sum>target){
                right=right->prev;
            }
            else{
                left=left->next;
            }
        }
        return ans;
    }
};