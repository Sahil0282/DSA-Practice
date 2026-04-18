#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n=nums.size();
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         int sum=0;
    //         for(int j=i;j<n;j++){
    //             sum+=nums[j];
    //             if(sum==goal){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n=nums.size();
    //     int left=0,right=0;
    //     int sum=0;
    //     int count=0;
    //     unordered_map<int,int> prefixCount;
    //     prefixCount[0] = 1;
    //     while(right<n){
    //         sum+=nums[right];
    //         int rem=sum-goal;
    //         if(prefixCount.find(rem)!=prefixCount.end()){
    //             count+=prefixCount[rem];
    //         }
    //         prefixCount[sum]++;
    //         right++;
    //     }
    //     return count;
    // }
    int atMost(vector<int>& nums, int goal){
        int n=nums.size();
        if(goal<0) return 0;
        int left=0,right=0,count=0;
        int sum=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout<<sol.numSubarraysWithSum(nums,goal)<<endl;
    return 0;
}