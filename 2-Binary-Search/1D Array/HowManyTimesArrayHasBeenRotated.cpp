#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n=nums.size();
        int low=0,high=n-1;
        int minEle=INT_MAX;
        int minIndex=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
               if(nums[low]<minEle){
                minEle=nums[low];
                minIndex=low;
               }
                break;
            }else if(nums[low]<=nums[mid]){
               if(nums[low]<minEle){
                    minEle=nums[low];
                    minIndex=low;
               }
                low=mid+1;
            }
            else if(nums[mid]<=nums[high]){
               if(nums[mid]<minEle){
                    minEle=nums[mid];
                    minIndex=mid;
               }
                high=mid-1;
            }
        }
        return minIndex;
    }
};
int main(){
    Solution sol;
    vector<int> nums={15,18,2,3,6,12};
    cout<<sol.findKRotation(nums)<<endl; // Output: 2
    return 0;
}