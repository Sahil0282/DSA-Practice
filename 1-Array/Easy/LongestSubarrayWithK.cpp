#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
  public:

    // Brute: O(n^2)
    // int longestSubarray(vector<int>& arr, int k) {
    //     int maxLen=0;
    //     int sum=0;
    //     int n=arr.size();
    //     for(int i=0;i<n;i++){
    //         sum=0;
    //         for(int j=i;j<n;j++){
    //             sum+=arr[j];
    //             if(sum==k)
    //                 maxLen=max(maxLen,j-i+1);
    //         }
    //     }
    //     return maxLen;
    // }

    // Optimal 1: O(n) using prefix sum + hashmap
    // int longestSubarray(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     int maxLen=0;
    //     long long sum=0;
    //     map<int,int> preSum;  // stores earliest index of that prefix sum
    //     
    //     for(int i=0;i<n;i++){
    //         sum+=arr[i];
    //         
    //         if(sum==k)
    //             maxLen=max(maxLen,i+1);
    //         
    //         long long rem=sum-k;
    //         if(preSum.find(rem)!=preSum.end()){
    //             int len=i-preSum[rem];
    //             maxLen=max(maxLen,len);
    //         }
    //         
    //         if(preSum.find(sum)==preSum.end())
    //             preSum[sum]=i;
    //     }
    //     return maxLen;
    // }

    // Optimal 2 (with handling duplicate prefix sums): O(n)
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        int maxLen=0;
        long long sum=0;
        map<int,int> preSum;  // stores earliest index of prefix sum

        for(int i=0;i<n;i++){
            sum+=arr[i];

            if(sum==k)
                maxLen=max(maxLen,i+1);

            long long rem=sum-k;
            if(preSum.find(rem)!=preSum.end()){
                int len=i-preSum[rem];
                maxLen=max(maxLen,len);
            }

            if(preSum.find(sum)==preSum.end())  // store earliest occurrence
                preSum[sum]=i;
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;
    int result = sol.longestSubarray(arr, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
    return 0;
}