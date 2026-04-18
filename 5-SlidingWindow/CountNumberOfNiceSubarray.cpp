#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int maxCount=0;
    //     int odds=0;
    //     for(int i=0;i<n;i++){
    //         odds=0;
    //         for(int j=i;j<n;j++){
    //             if(nums[j]%2==1){
    //                 odds++;
    //             }
    //             if(odds==k){
    //                 maxCount++;
    //             }
    //         }
    //     }
    //     return maxCount;
    // }

    // int atMost(vector<int>& nums, int k){
    //     int n=nums.size();
    //     int maxCount=0;
    //     int odds=0;
    //     int sum=0;
    //     int left=0,right=0;
    //     while(right<n){
    //         // if(nums[right]%2==1) odds++;
    //         sum+=nums[right]%2;
    //         // while(odds>k){
    //         while(sum>k){
    //             // if(nums[left]%2==1) odds--;
    //             sum-=nums[left]%2;
    //             left++; 
    //         }
    //         maxCount+=right-left+1;
    //         right++;
    //     }
    //     return maxCount;
    // }
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     return atMost(nums,k)-atMost(nums,k-1);
    // }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxCount=0;
        unordered_map<int,int> preSum;
        preSum[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]%2;
            maxCount+=preSum[sum-k];
            preSum[sum]++;
        }
        return maxCount; 
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,1,2,1,1};
    int k=3;
    cout<<sol.numberOfSubarrays(nums,k)<<endl; // Output: 2
    return 0;
}