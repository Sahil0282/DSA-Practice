#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPlace(vector<int> &nums, int k,int maxDistance){
        int n=nums.size();
        int count=1;
        int currentCow=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-currentCow>=maxDistance){
                count++;
                currentCow=nums[i];
            }
        }
        return count>=k;
    }
    // int aggressiveCows(vector<int> &nums, int k) {
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     if(k==2) return nums[n-1]-nums[0];
    //     int low=*min_element(nums.begin(),nums.end());
    //     int high=*max_element(nums.begin(),nums.end());
    //     for(int i=low;i<=high;i++){
    //         if(canPlace(nums,k,i)) return i;
    //     }
    //     return -1;
    // }
    int aggressiveCows(vector<int> &nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(k==2) return nums[n-1]-nums[0];
        int low=1;
        int high=nums[n-1]-nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPlace(nums,k,mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
int main(){
    Solution sol;
    vector<int> stalls={1,2,4,8,9};
    int k=3;
    cout<<sol.aggressiveCows(stalls,k);
    return 0;
}