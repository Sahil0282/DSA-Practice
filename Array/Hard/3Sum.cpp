#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Brute Force Approch:
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 vector<int> sum;
//                 for(int k=j+1;k<n;k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int> sum={nums[i],nums[j],nums[k]};
//                         sort(sum.begin(),sum.end());
//                         st.insert(sum);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };

//Better Apprch
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
//            set<int> preSum;
//             for(int j=i+1;j<n;j++){
//                 int rem=-(nums[i]+nums[j]);
//                 if(preSum.find(rem)!=preSum.end()){
//                     vector<int> sum={nums[i],nums[j],rem};
//                     sort(sum.begin(),sum.end());
//                     st.insert(sum);
//                 }
//                 preSum.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };

//Optimal Approch
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> res={nums[i],nums[j],nums[k]};
                    ans.push_back(res);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }else if(sum<0) j++;
                else k--;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=s.threeSum(nums);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}