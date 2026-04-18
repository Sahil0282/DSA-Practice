#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int n=nums.size();
        int maxCount=0;
        int left=0,right=0;
        unordered_map<int,int> freq;
        while(right<n){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0) freq.erase(nums[left]);
                left++;
            }
            //All subarrays ending at right and starting from left to right are valid
            maxCount+=(right-left+1);
            right++;
        }
        return maxCount;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }

    // int subarraysWithKDistinct(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         unordered_map<int,int> freq;
    //         for(int j=i;j<n;j++){
    //             freq[nums[j]]++;
    //             if(freq.size()==k) count++;
    //             if(freq.size()>k) break;
    //         }
    //     }
    //     return count;
    // }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl; // Output: 7
    return 0;
}