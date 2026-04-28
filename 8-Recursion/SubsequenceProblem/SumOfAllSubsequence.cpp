#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int findSum(vector<int>& nums,int sum,int idx){
        if(idx==nums.size()){
            return sum;
        }
        int left=findSum(nums,sum+nums[idx],idx+1);
        int right=findSum(nums,sum,idx+1);
        return left+right;
    }
    int sumOfAllSubsequences(vector<int>& nums){
        return findSum(nums,0,0);
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    cout<<s.sumOfAllSubsequences(nums)<<endl;
    return 0;
}

