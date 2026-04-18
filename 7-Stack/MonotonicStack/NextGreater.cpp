#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         stack<int> st;
//         unordered_map<int,int> ans;
//         for(int i=nums2.size()-1;i>=0;i--){
//             while(!st.empty() && st.top()<=nums2[i]){
//                 st.pop();
//             }
//             ans[nums2[i]]=st.empty()?-1:st.top();
//             st.push(nums2[i]);
//         }
//         vector<int> res;
//         for(auto it:nums1){
//             res.push_back(ans[it]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            int j=0;
            while(j<n2 && nums2[j]!=nums1[i]){
                j++;
            }
            int flag=0;
            for(int k=j+1;k<n2;k++){
                if(nums2[k]>nums1[i]){
                    flag=1;
                    ans.push_back(nums2[k]);
                    break;
                }
            }
            if(flag==0) ans.push_back(-1);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int val : result) {
        cout << val << " "; // Output: -1 3 -1
    }
    cout << endl;
    return 0;
}