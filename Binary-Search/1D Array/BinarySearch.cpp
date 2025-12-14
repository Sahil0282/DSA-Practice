#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Optimal Solution with TC O(log n)
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if (nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};
int main(){
    Solution obj;
    vector<int> nums={-1,0,3,5,9,12};
    int target=9;
    cout<<obj.search(nums,target);
    return 0;
}