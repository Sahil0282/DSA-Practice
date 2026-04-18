#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// ─────────────────────────────────────────────
// Brute Force | TC: O(n³ log n) | SC: O(triplets)
// ─────────────────────────────────────────────
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//
//         // set<vector<int>> stores only unique triplets automatically
//         set<vector<int>> st;
//
//         // try every possible combination of 3 indices
//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 for(int k = j+1; k < n; k++) {
//                     if(nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> sum = {nums[i], nums[j], nums[k]};
//                         // sort before inserting so {-1,0,1} and {1,0,-1}
//                         // are treated as the same triplet by the set
//                         sort(sum.begin(), sum.end());
//                         st.insert(sum);
//                     }
//                 }
//             }
//         }
//         return vector<vector<int>>(st.begin(), st.end());
//     }
// };

// ─────────────────────────────────────────────
// Better Approach | TC: O(n² log n) | SC: O(n)
// ─────────────────────────────────────────────
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//
//         // set handles duplicate triplets automatically
//         set<vector<int>> st;
//
//         for(int i = 0; i < n; i++) {
//             // fix nums[i] as first element of triplet
//             // problem reduces to: find nums[j] + nums[k] = -(nums[i])
//             // this is exactly Two Sum — use HashSet for O(1) lookup
//
//             set<int> seen; // tracks elements seen so far for this i
//             for(int j = i+1; j < n; j++) {
//                 int rem = -(nums[i] + nums[j]); // third element we need
//
//                 if(seen.find(rem) != seen.end()) {
//                     vector<int> sum = {nums[i], nums[j], rem};
//                     sort(sum.begin(), sum.end());
//                     st.insert(sum);
//                 }
//                 // insert AFTER checking — so nums[j] isn't used as both
//                 // nums[j] and rem at the same time (can't use one element twice)
//                 seen.insert(nums[j]);
//             }
//         }
//         return vector<vector<int>>(st.begin(), st.end());
//     }
// };

// ─────────────────────────────────────────────
// Optimal Approach | TC: O(n²) | SC: O(1)
// ─────────────────────────────────────────────
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // sorting is mandatory — enables two pointer logic
        // (moving pointers has predictable effect on sum only when sorted)
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // skip duplicate i — same nums[i] would produce same triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // optimization: if smallest element > 0,
            // sum can never be 0 (all remaining are also > 0)
            if(nums[i] > 0) break;

            int j = i+1;  // left pointer starts just after i
            int k = n-1;  // right pointer starts at end

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    // skip duplicates after finding triplet
                    // so we don't add the same triplet again
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;

                } else if(sum < 0) {
                    j++;  // sum too small → move left pointer right (bigger value)
                } else {
                    k--;  // sum too big → move right pointer left (smaller value)
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = s.threeSum(nums);
    for(auto it : ans) {
        for(auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}