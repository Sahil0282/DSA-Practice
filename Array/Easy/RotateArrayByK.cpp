#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     int n=nums.size();
    //     k=k%n;
    //     for(int i=n-k;i<n;i++){
    //         ans.push_back(nums[i]);
    //     }
    //     for(int i=n-k-1;i>=0;i--){
    //         nums[i+k]=nums[i];
    //     }
    //     for(int i=0;i<k;i++){
    //         nums[i]=ans[i];
    //     }
    // }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    sol.rotate(nums, k);
    cout << "Rotated Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}