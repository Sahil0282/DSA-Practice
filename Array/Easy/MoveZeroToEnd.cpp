#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int i=0;
    //     int n=nums.size();
    //     for(int j=0;j<n;j++){
    //         if(nums[j]!=0){
    //             swap(nums[i],nums[j]);
    //             i++;
    //         }
    //     }
    // }
        
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) ans.push_back(nums[i]);
        }
        int cnt=ans.size();
        for(int i=0;i<cnt;i++){
            nums[i]=ans[i];
        }
        for(int i=cnt;i<n;i++){
            nums[i]=0;
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    cout << "Array after moving zeros to the end: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
