#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
// Brute Force Approch With TC O(n^4) and SC O(no of subarrays)
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     for(int l=k+1;l<n;l++){
//                         if(nums[i]+nums[j]+nums[k]+nums[l]==target){
//                             vector<int> sum={nums[i],nums[j],nums[k],nums[l]};
//                             sort(sum.begin(),sum.end());
//                             st.insert(sum);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };

//Better Solution
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 set<int> targetSum;
//                 for(int k=j+1;k<n;k++){
//                     long long rem=(long long)target-((long long)nums[i]+nums[j]+nums[k]);
//                     if(targetSum.find(rem)!=targetSum.end()){
//                         vector<int> sum={nums[i],nums[j],nums[k],(int)rem};
//                         sort(sum.begin(),sum.end());
//                         st.insert(sum);
//                     }
//                     targetSum.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans; 
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum = (long long)nums[i] 
                                + nums[j] 
                                + nums[k] 
                                + nums[l];
                    if(sum==target){
                        vector<int> res={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(res);
                        k++;
                        l--;

                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=s.fourSum(nums,target);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}