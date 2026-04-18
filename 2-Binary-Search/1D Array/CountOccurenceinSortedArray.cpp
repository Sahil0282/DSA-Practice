#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getStart(const vector<int>& nums, int target){
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
    int getEnd(const vector<int>& nums, int target){
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
    int countOccurrences(const vector<int>& arr, int target) {
        int start=getStart(arr,target);
        if(start==-1) return -1;
        int end=getEnd(arr,target);
        return end-start+1;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1,2,2,2,3,4,5};
    int target = 2;
    int count = sol.countOccurrences(arr, target);
    if(count != -1)
        cout << "The element " << target << " occurs " << count << " times in the array." << endl;
    else
        cout << "The element " << target << " is not present in the array." << endl;
    return 0;
}