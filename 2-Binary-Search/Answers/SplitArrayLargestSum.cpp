#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canSplit(vector<int>& nums, int k,int maxSum){
        int sum=nums[0];
        int count=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(sum+nums[i]<=maxSum){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
            }
        }
        return count<=k;
    }
    // int splitArray(vector<int>& nums, int k) {
    //     int low=*max_element(nums.begin(),nums.end());
    //     int high=accumulate(nums.begin(),nums.end(),0);
    //     for(int i=low;i<=high;i++){
    //         if(canSplit(nums,k,i)) return i;
    //     }
    //     return -1;
    // }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSplit(nums,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> nums={7,2,5,10,8};
    int k=2;
    cout<<sol.splitArray(nums,k);
    return 0;
}