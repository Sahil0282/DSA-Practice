#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void combination(vector<int>& nums,vector<int>& ans,vector<vector<int>>& res,int target,int idx){
        if(idx==nums.size()){
            if(target==0){
                res.push_back(ans);
            }
            return;
        }
        if(nums[idx]<=target){
            ans.push_back(nums[idx]);
            combination(nums,ans,res,target-nums[idx],idx+1);
            ans.pop_back();
        }
        while(idx<nums.size()-1 && nums[idx]==nums[idx+1]) idx++;
        combination(nums,ans,res,target,idx+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        combination(candidates,ans,res,target,0);
        return res;
    }
};
int main(){
    Solution s;
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> res=s.combinationSum2(candidates,target);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}