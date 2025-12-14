#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int ans=-1,low=0,high=n-1;
    //     while(low<=high){
    //         int mid=low+(high-low)/2;
    //         if(nums[mid]==target){
    //             ans=mid;
    //             break;
    //         }else if(nums[mid]>target) high=mid-1;
    //         else low=mid+1;
    //     }
    //     if(ans==-1) return {-1,-1};
    //     int start=ans,end=ans;
    //     while(start>=0 && nums[start]==nums[start-1]) start--;
    //     while(end<n && nums[end]==nums[end+1]) end--;
    //     return {start,end};
    // }

    int getStart(vector<int>& nums, int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    int getEnd(vector<int>& nums, int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=getStart(nums,target);
        if(start==-1) return {-1,-1};
        int end=getEnd(nums,target);
        return {start,end};
    }
};
int main(){
    Solution sol;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=sol.searchRange(nums,target);
    cout<<"First Position: "<<ans[0]<<", Last Position: "<<ans[1]<<endl;
    return 0;
}