#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            if(nums[mid]<nums[mid+1]) low=mid+1;
            else if(nums[mid]>nums[mid+1]) high=mid-1;
            else high=mid-1;
        }
        return -1;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,1,3,5,6,4};
    cout<<sol.findPeakElement(nums)<<endl; // Output: 5
    return 0;
}