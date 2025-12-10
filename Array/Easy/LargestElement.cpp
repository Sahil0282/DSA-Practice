#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // int largestElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     // return nums.back();
    //     return nums[nums.size() - 1];
    // }
    int largestElement(vector<int>& nums) {
        int maxElement = nums[0];
        for (int num : nums) {
            if (num > maxElement) {
                maxElement = num;
            }
        }
        return maxElement;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    cout << "The largest element is: " << sol.largestElement(nums) << endl;
    return 0;
}
        