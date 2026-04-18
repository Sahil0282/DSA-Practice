#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> nums={1,2,4,4,5,6,8};
    int x=4;
    cout<<obj.upperBound(nums,x);
    return 0;
}