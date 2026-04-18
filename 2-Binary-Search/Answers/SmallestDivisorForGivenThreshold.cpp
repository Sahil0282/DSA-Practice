#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canDivide(vector<int>& nums, int threshold,int minDivisor){
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=ceil((double)nums[i]/double(minDivisor));
            if(totalSum>threshold) return false;
        }
        return totalSum<=threshold;
    }
    // int smallestDivisor(vector<int>& nums, int threshold) {
    //     int low=1,high=*max_element(nums.begin(),nums.end());
    //     for(int i=low;i<=high;i++){
    //         if(canDivide(nums,threshold,i)) return i;
    //     }
    //     return -1;
    // }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDivide(nums,threshold,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,5,9};
    int threshold=6;
    cout<<sol.smallestDivisor(nums,threshold)<<endl; // Output: 5
    return 0;
}