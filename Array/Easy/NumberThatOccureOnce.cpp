#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count==1) return nums[i];
        }
        return -1;
    }
    //Better: O(n) and SC O(n)
    // int singleNumber(vector<int>& nums) {
    //     map<int,int> freq;
    //     for(auto it:nums){
    //         freq[it]++;
    //     }
    //     for(auto it:freq){
    //         if(it.second==1) return it.first;
    //     }
    //     return -1;
    // }
    //Optimal: O(n) and SC O(1)
    // int singleNumber(vector<int>& nums) {
    //     int Xor=0;
    //     for(int i=0;i<nums.size();i++){
    //         Xor^=nums[i];
    //     }
    //     return Xor;
    // }
};
int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = sol.singleNumber(nums);
    cout << "The number that occurs once is: " << result << endl;
    return 0;
}