#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxJump=0,maxIndex=0,currentEnd=0;
        for(int i=0;i<n-1;i++){
            maxIndex=max(maxIndex,nums[i]+i);
            if(i==currentEnd){
                maxJump++;
                currentEnd=maxIndex;
            }
        }
        return maxJump;
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,3,1,1,4};
    cout<<sol.jump(nums)<<endl; 
    return 0;
}