#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // BRUTE FORCE - O(n^2) TC | O(1) SC
    // try every subarray, track running product, update max
    // int maxProduct(vector<int>& nums) {
    //     int n=nums.size();
    //     int maxProduct=0;
    //     for(int i=0;i<n;i++){
    //         int product=1;
    //         for(int j=i;j<n;j++){
    //             product*=nums[j];
    //             maxProduct=max(maxProduct,product);
    //         }
    //     }
    //     return maxProduct;
    // }

    // OPTIMAL - O(n) TC | O(1) SC
    // maxSoFar = maximum product of any subarray ending at current index
    // minSoFar = minimum product of any subarray ending at current index
    // minSoFar is tracked because if nums[i] is negative,
    // most negative × negative = largest positive (roles flip)
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        // initialize both trackers and answer with first element
        int maxSoFar=nums[0];
        int minSoFar=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            // multiplying by negative flips the roles of max and min
            // so swap them first, then multiply — order is critical
            if(nums[i]<0){
                swap(maxSoFar,minSoFar);
            }
            // compare with nums[i] alone to allow fresh start
            // handles the case where previous product is worse than starting over
            maxSoFar=max(nums[i],maxSoFar*nums[i]);
            minSoFar=min(nums[i],minSoFar*nums[i]);

            // update global answer
            ans=max(ans,maxSoFar);
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 3, -2, 4};
    int result = solution.maxProduct(nums);
    cout << "Maximum product of a contiguous subarray: " << result << endl; // Output: Maximum product of a contiguous subarray: 6
    return 0;
}