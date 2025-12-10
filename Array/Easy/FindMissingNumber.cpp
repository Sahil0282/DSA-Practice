#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // Brute: O(n^2)
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    flag=1;
                    break;
                }
            }
            if (flag==0)
            {
                return i;
            }
        }
    }
    // Better1: Using HashMap O(n) and SC O(n)
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     map<int,int> freq;
    //     for(auto it:nums){
    //         freq[it]++;
    //     }
    //     for(int i=0;i<=n;i++){
    //         if(freq.find(i)==freq.end()) return i;
    //     }
    //     return -1;
    // }

    // Better2: Using Array O(n) and SC O(n)
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     int[n+1] =freq{0};
    //     for(auto it:nums){
    //         freq[it]++;
    //     }
    //     for(int i=0;i<=n;i++){
    //         if(freq[i]==0) return i;
    //     }
    //     return -1;
    // }

    // Optimal: Using Maths O(n) and SC O(1)
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     int total=0;
    //     for(int i=0;i<n;i++) total+=nums[i];  
    //     int sum = n * (n + 1) / 2;
    //     return sum-total;
    // }
    
    // Optimal: Using XOR O(n) and SC O(1)
    // int missingNumber(vector<int>& nums){
    //     int XorFull=0;
    //     int XorArr=0;
    //     for(int i=0;i<nums.size();i++){
    //         XorFull^=i+1;
    //         XorArr^=nums[i];
    //     }
    //     return XorFull^XorArr;
    // }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    int missing = sol.missingNumber(nums);
    cout << "Missing number: " << missing << endl;
    return 0;
}