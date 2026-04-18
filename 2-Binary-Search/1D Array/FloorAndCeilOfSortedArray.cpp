#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getFloor(vector<int> nums, int x){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=x){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
    int getCeil(vector<int> nums, int x){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=x){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int flr=getFloor(nums,x);
        int cil=getCeil(nums,x);
        return {nums[flr],nums[cil]};
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,8,10,10,12,19};
    int x=5;
    vector<int> ans=sol.getFloorAndCeil(nums,x);
    cout<<"Floor: "<<ans[0]<<", Ceil: "<<ans[1]<<endl;
    return 0;
}