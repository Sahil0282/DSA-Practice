#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid]&& nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            else if(nums[low]<=nums[mid]){
                if(nums[mid]>=target && target>=nums[low]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,5,6,0,0,1,2};
    int target=0;
    cout<<sol.search(nums,target)<<endl; // Output: 1 (true)
    target=3;
    cout<<sol.search(nums,target)<<endl; // Output: 0 (false)
    return 0;
}   