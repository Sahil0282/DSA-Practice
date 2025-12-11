#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Better approch O(N^2) time and O(1) space
    // int maxSubArray(vector<int>& nums) {
    //     int n=nums.size();
    //     int maxSum=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         int sum=0;
    //         for(int j=i;j<n;j++){
    //             sum+=nums[j];
    //             maxSum=max(maxSum,sum);
    //         }
    //     }
    //     return maxSum;
    // }

    //Optimal approch (strivers) But fails for all negative array elements O(N) time and O(1) space
    // int maxSubArray(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1) return nums[0];
    //     int sum=0;
    //     int maxSum=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         sum+=nums[i];
    //         if(sum<0){
    //             sum=0;
    //         }
    //         maxSum=max(maxSum,sum);
    //     }
    //     return maxSum;
    // }

    //Optimal approch (Kadane's Algorithm) O(N) time and O(1) space
    /* Dry run:
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    i=0: currentSum = -2, maxSum = -2
    i=1: currentSum = max(1, -2 + 1) = 1, maxSum = max(-2, 1) = 1
    i=2: currentSum = max(-3, 1 - 3) = -2, maxSum = max(1, -2) = 1
    i=3: currentSum = max(4, -2 + 4) = 4, maxSum = max(1, 4) = 4
    i=4: currentSum = max(-1, 4 - 1) = 3, maxSum = max(4, 3) = 4
    i=5: currentSum = max(2, 3 + 2) = 5, maxSum = max(4, 5) = 5
    i=6: currentSum = max(1, 5 + 1) = 6, maxSum = max(5, 6) = 6
    i=7: currentSum = max(-5, 6 - 5) = 1, maxSum = max(6, 1) = 6
    i=8: currentSum = max(4, 1 + 4) = 5, maxSum = max(6, 5) = 6
    Result: maxSum = 6
    */

    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int currentSum=nums[0];
        for(int i=1;i<n;i++){
            currentSum=max(nums[i],currentSum+nums[i]);
            maxSum=max(maxSum,currentSum);
        }
        return maxSum;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}