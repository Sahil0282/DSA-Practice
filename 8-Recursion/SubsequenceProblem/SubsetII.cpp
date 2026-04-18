#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& subset,vector<int>& ans,int i){
        if(i>=nums.size()){
            subset.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        backtrack(nums,subset,ans,i+1);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        backtrack(nums,subset,ans,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        backtrack(nums,subset,ans,0);
        return subset;
    }
};
int main(){
    Solution s;
    vector<int> arr={1,2,2};
    vector<vector<int>> ans=s.subsetsWithDup(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}