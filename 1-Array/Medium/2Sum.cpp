#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    //Optimal approach O(n) time and O(n) space
    // if we have to return indices then this approch is optimal
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     map<int,int> preSum;
    //     for(int i=0;i<n;i++){
    //         int rem=target-nums[i];
    //         if(preSum.find(rem)!=preSum.end()){
    //             return {preSum[rem],i};
    //         }
    //         preSum[nums[i]]=i;
    //     }
    //     return {-1,-1};
    // }

    //Optimal approach O(nlogn) time and O(1) space
    // if we just have to return that two no exisit or not so for this this is optimal
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int i=0,j=n-1;
    //     int sum=0;
    //     while(i<=j){
    //         sum=nums[i]+nums[j];
    //         if(sum>target){
    //             j--;
    //         }else if(sum==target){
    //             return true;
    //         }else{
    //             i++;
    //         }
    //     }
    //     return false;
    // }

    //Brute force O(n^2) time and O(1) space
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> result=sol.twoSum(nums,target);
    cout<<"Indices of the two numbers are: "<<result[0]<<" and "<<result[1]<<endl;
    return 0;
}