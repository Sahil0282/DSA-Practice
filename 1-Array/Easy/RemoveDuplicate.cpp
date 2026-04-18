#include <iostream> 
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    //Optimal  O(n)
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
    //Brute TC O(2n) and SC O(n)
    // int removeDuplicates(vector<int>& nums) {
    //     vector<int> ans;
    //     ans.push_back(nums[0]);
    //     int n=nums.size();
    //     for(int j=1;j<n;j++){
    //         if(nums[j]!=ans.back()) ans.push_back(nums[j]);
    //     }
    //     int index=0;
    //     for(int i=0;i<ans.size();i++){
    //         nums[index]=ans[index];
    //         index++;
    //     }
    //     return index;
    // }
    //Brute TC O(n) and SC O(n)
    // int removeDuplicates(vector<int>& nums) {
    //     unordered_set<int> ans;
    //     int index=0;
    //     for(auto it:nums){
    //         if(ans.find(it)==ans.end()){
    //             ans.insert(it);
    //             nums[index]=it;
    //             index++;
    //         }
    //     }
    //     return index;
    // }
    //Brute TC O(n log n) and SC O(n)
    // int removeDuplicates(vector<int>& nums) {
    //     set<int> ans;
    //     int index=0;
    //     for(auto it:nums){
    //         ans.insert(it); 
    //     }
    //     for(auto it:ans){
    //         nums[index]=it;
    //         index++;
    //     }    
    //     return index;
    // }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = sol.removeDuplicates(nums);
    cout << "The length after removing duplicates is: " << newLength << endl;
    cout << "The modified array is: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}