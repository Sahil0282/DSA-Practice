#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(i>maxIndex) return false;
            maxIndex=max(maxIndex,i+nums[i]);
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,3,1,1,4};
    cout<<sol.canJump(nums)<<endl; // Output: 1 (true)
    return 0;
}