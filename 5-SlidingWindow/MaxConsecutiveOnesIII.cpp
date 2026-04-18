#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     int left=0;
    //     int right=0;
    //     int n=nums.size();
    //     int maxCount=0;
    //     int x=k;
    //     while(right<n){
    //         if(nums[right]==1){
    //             right++;
    //         }else if(x>0){
    //             x--;
    //             right++;
    //         }else{
    //             if(nums[left]==0){
    //                 x++;
    //             }
    //             left++;
    //         }
    //         maxCount=max(maxCount,right-left);
    //     }
    //     return maxCount;
    // }

    // int longestOnes(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int maxCount=0,count=0;
    //     int x=k;
    //     for(int i=0;i<n;i++){
    //         x=k;
    //         count=0;
    //         for(int j=i;j<n;j++){
    //             if(nums[j]==1){
    //                 count++;
    //             }else if(x>0){
    //                 x--;
    //                 count++;
    //             }else{
    //                 break;
    //             }
    //         }
    //         maxCount=max(maxCount,count);
    //     }
    //     return maxCount;
    // }
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxCount=0,count=0;
        int zeroCount=0;
        int left=0,right=0;
        while(right<n){
            if(nums[right]==0) zeroCount++;
            while(zeroCount>k){
                if(nums[left]==0) zeroCount--;
                left++;
            }
            maxCount=max(maxCount,right-left+1);
            right++;
        }
        return maxCount;
    }

};
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl; // Output: 6
    return 0;
}