#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int minEle=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
                minEle=min(minEle,nums[low]);
                break;
            }else if(nums[low]<=nums[mid]){
                minEle=min(minEle,nums[low]);
                low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
                minEle=min(minEle,nums[mid]);
                high=mid-1;
            }
        }
        return minEle;
    }
};
int main(){
    Solution sol;
    vector<int> nums={3,4,5,1,2};
    cout<<sol.findMin(nums)<<endl; // Output: 1
    return 0;
}