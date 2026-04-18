#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        // Deque stores INDICES of elements
        // The values at those indices are kept in DECREASING order
        // Front of deque always contains index of maximum element of current window
        deque<int> dq;

        for (int i = 0; i < n; i++) {

            // 1. Remove indices that are OUTSIDE the current window
            // Current window range is [i - k + 1 , i]
            // So any index <= i - k is no longer useful
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order in deque
            // Remove all indices from back whose values are smaller than
            // or equal to current element, because they can never be
            // maximum for this or any future window
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Add current element index to deque
            dq.push_back(i);

            // 4. Once the first window of size k is formed (i >= k - 1),
            // the front of deque contains the index of the maximum element
            // for the current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}