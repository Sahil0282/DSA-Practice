#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    // Brute Force Approach O(N^2) time and O(1) space
    // int majorityElement(vector<int>& nums) {
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         int count=0;
    //         for(int j=0;j<n;j++){
    //             if(nums[i]==nums[j]) count++;
    //         }
    //         if(count>(n/2)) return nums[i];
    //     }
    //     return -1;
    // }
    // Optimal Approach O(N) time and O(N) space boyer moore voting algorithm
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        for(auto it:freq){
            if(it.second>(n/2)) return it.first;
        }
        return -1;
    }
    // Better Approach O(N) time and O(1) space
    // int majorityElement(vector<int>& nums) {
    //     int n=nums.size();
    //     int candidate=nums[0];
    //     int count=1;
    //     for(int i=1;i<n;i++){
    //         if(count==0){
    //             candidate=nums[i];
    //             count=1;
    //         }
    //         else if(candidate==nums[i]) count++;
    //         else count--;
    //     }
    //     return candidate;
    // }
};
int main(){
    Solution sol;
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<"Majority element is: "<<sol.majorityElement(nums)<<endl;
    return 0;
}