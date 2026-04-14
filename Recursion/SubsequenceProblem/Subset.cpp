#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    void backtrack(vector<int>& nums,vector<vector<int>>& subset,vector<int>& ans,int idx){
        if(idx>=nums.size()){
            subset.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        backtrack(nums,subset,ans,idx+1);
        ans.pop_back();
        backtrack(nums,subset,ans,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> subset;
        vector<int> ans;
        backtrack(arr,subset,ans,0);
        return subset;
        
    }
};
int main(){
    Solution s;
    vector<int> arr={1,2,2};
    vector<vector<int>> ans=s.subsets(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}