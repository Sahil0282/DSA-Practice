#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool countSub(vector<int>& nums,int k,int sum,int idx){
        if(idx==nums.size()){
            return sum==k;
        }
        if(countSub(nums,k,sum+nums[idx],idx+1)) return true;
        if(countSub(nums,k,sum,idx+1)) return true;
        return false;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return countSub(nums,k,0,0);
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,1};
    int k=2;
    cout<<s.checkSubsequenceSum(nums,k)<<endl;
    return 0;
}