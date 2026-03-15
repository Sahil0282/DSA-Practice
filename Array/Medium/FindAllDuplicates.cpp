#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    // BRUTE FORCE - O(n^2) TC | O(n) SC
    // for each element, count its frequency across the entire array
    // if frequency == 2, insert into set (set avoids duplicates in result)
    // vector<int> findDuplicates(vector<int>& nums) {
    //     int n=nums.size();
    //     set<int> res;
    //     for(int i=0;i<n;i++){
    //         int count=0;
    //         for(int j=0;j<n;j++){
    //             if(nums[i]==nums[j]){
    //                 count++;
    //             }
    //         }
    //         if(count==2) res.insert(nums[i]);
    //     }
    //     vector<int> ans(res.begin(),res.end());
    //     return ans;
    // }

    // BETTER - O(n) TC | O(n) SC
    // use a hashmap to count frequency of each element
    // return those elements whose frequency was 2
    // still uses O(n) extra space for the hashmap
    // vector<int> findDuplicates(vector<int>& nums) {
    //     int n=nums.size();
    //     unordered_map<int,int> mp;
    //     vector<int> ans;
    //     for(auto it:nums){
    //         mp[it]++;
    //     }
    //     for(auto it:mp){
    //         if(it.second==2) ans.push_back(it.first);
    //     }
    //     return ans;
    // }

    // OPTIMAL - O(n) TC | O(1) SC
    // the problem states all integers are in range [1, n] and array size is n
    // this means every value v has a valid corresponding index (v-1)
    // so we can use the array itself as a visited marker — no extra space needed
    // when we visit index idx for the first time, we negate nums[idx] to mark it as visited
    // if we visit idx again and find nums[idx] is already negative,
    // it means we have seen this value before — so we push idx+1 (the original value) into ans
    // abs(nums[i]) is used when computing idx because nums[i] itself
    // may have been negated by a previous step
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]<0){
                ans.push_back(idx+1);
            }else{
                nums[idx]=-nums[idx];
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = solution.findDuplicates(nums);
    for(int num : result) {
        cout << num << " "; // Output: 2 3
    }
    cout << endl;
    return 0;
}