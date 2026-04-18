#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //Better Approch Using HashMap TC o(n) and SC 
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n=nums.size();
    //     unordered_map<int,int> freq;
    //     vector<int> ans;
    //     for(auto it:nums){
    //         freq[it]++;
    //     }
    //     for(auto it:freq){
    //         if(it.second>(n/3)){
    //             ans.push_back(it.first);
    //         }
    //     }
    //     return ans;

    //Brute FOrce Apprch with TC O(n^2) and SC O(n);
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> ans;
    //     for(int i=0;i<n;i++){
    //         int count=0;
    //         for(int j=0;j<n;j++){
    //             if(nums[i]==nums[j]) count++;
    //         }
    //         if(count>(n/3)){
    //             if(find(ans.begin(),ans.end(),nums[i])==ans.end()) ans.push_back(nums[i]);
    //         }
    //     }
    //     return ans;
    // }

    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int el1=INT_MIN,el2=INT_MIN;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
        }
        if(cnt1>(n/3)) ans.push_back(el1);
        if(cnt2>(n/3)) ans.push_back(el2);

        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums={3,3,3,1,1,2,2,2};
    vector<int> ans=s.majorityElement(nums);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}