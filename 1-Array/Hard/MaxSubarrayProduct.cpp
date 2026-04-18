#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Brute Force:
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    // int bruteMaxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxProd = nums[0];

    //     for(int i = 0; i < n; i++){
    //         int prod = 1;
    //         for(int j = i; j < n; j++){
    //             prod *= nums[j];
    //             maxProd = max(maxProd, prod);
    //         }
    //     }
    //     return maxProd;
    // }


    // Optimal:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0]; 
        // maximum product ending at current index

        int minProd = nums[0]; 
        // minimum product ending at current index (important for handling negatives)

        int result = nums[0]; 
        // stores the overall maximum product

        for(int i = 1; i < n; i++){

            if(nums[i] < 0){ 
                // if current number is negative, 
                // swap because max can become min and min can become max
                swap(maxProd, minProd);
            }

            maxProd = max(nums[i], nums[i] * maxProd); 
            // either start new subarray from nums[i]
            // OR extend previous max product

            minProd = min(nums[i], nums[i] * minProd); 
            // same logic for min (needed for future negative cases)

            result = max(maxProd, result); 
            // update global maximum
        }

        return result;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << s.maxProduct(nums) << endl;
    return 0;
}