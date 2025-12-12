#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //Intution: Using two nested loops to consider all subarrays and count those with sum equal to k.
    //Brute Force Approach: O(n^2) time complexity
    // int subarraySum(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         int sum=0;
    //         for(int j=i;j<n;j++){
    //             sum+=nums[j];
    //             if(sum==k) count++;
    //         }
    //     }
    //     return count;
    // }

    //Optimal Approach: Using prefix sum and hashmap to store frequency of prefix sums.
    // Time Complexity: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> preSum;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            int rem=sum-k;
            if(preSum.find(rem)!=preSum.end()){
                count+=preSum[rem];
            }
            preSum[sum]++;
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;
    return 0;
}