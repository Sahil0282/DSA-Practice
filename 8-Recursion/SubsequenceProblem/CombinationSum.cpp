#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void combination(vector<int>& nums,vector<int> &ans,vector<vector<int>> &res,int target,int idx){
        if(idx==nums.size()){
            if(target==0){
                res.push_back(ans);
            }
            return;
        }
        if(nums[idx]<=target){
            ans.push_back(nums[idx]);
            combination(nums,ans,res,target-nums[idx],idx);
            ans.pop_back();
        }
        combination(nums,ans,res,target,idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        combination(candidates,ans,res,target,0);
        return res;
    }
};
int main(){
    Solution s;
    vector<int> candidates={2,3,6,7};
    int target=7;
    vector<vector<int>> res=s.combinationSum(candidates,target);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}