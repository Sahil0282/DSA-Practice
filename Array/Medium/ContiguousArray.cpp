#include <iostream>
using namespace std;
//and for brute force approach we can use two loops and check for each subarray if it has equal number of 0s and 1s and keep track of the maximum length of such subarray. But this approach will have a time complexity of O(n^2) which is not efficient for large input sizes.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==0) nums[i]=-1;
        }
        unordered_map<int,int> preSum;
        preSum[0]=-1;
        int maxLen=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(preSum.find(sum)!=preSum.end()){
                maxLen=max(maxLen,i-preSum[sum]);
            }
            if(preSum.find(sum)==preSum.end()){
                preSum[sum]=i;
            }
        }
        return maxLen;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 1, 0};
    int result = solution.findMaxLength(nums);
    cout << "Maximum length of contiguous subarray with equal number of 0s and 1s: " << result << endl; // Output: Maximum length of contiguous subarray with equal number of 0s and 1s: 4
    return 0;
}