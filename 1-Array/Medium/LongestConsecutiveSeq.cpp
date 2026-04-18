#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    //Brute Approch O(n^2)
    // bool LinearSearch(vector<int>& nums,int tg){
    //     int n=nums.size();
    //     for(auto num:nums){
    //         if(num==tg) return true;
    //     }
    //     return false;
    // }
    // int longestConsecutive(vector<int>& nums) {
    //     int n=nums.size();
    //     int maxLength=0;
    //     for(int i=0;i<n;i++){
    //         int num=nums[i];
    //         int cnt=1;
    //         while(LinearSearch(nums,num+1)){
    //             num+=1;
    //             cnt++;
    //         }
    //         maxLength=max(maxLength,cnt);
    //     }
    //     return maxLength;
    // }

    //Better Approch O(nlogn)
    //  int longestConsecutive(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==0) return 0;
    //     sort(nums.begin(),nums.end());
    //     int maxLength=1;
    //     int lastSmaller=nums[0];
    //     int count=1;
    //     for(int i=1;i<n;i++){
    //         if(nums[i]==lastSmaller) continue;
    //         if(lastSmaller+1==nums[i]){
    //             count++;
    //         }else if(lastSmaller+1!=nums[i]){
    //             count=1;
    //         }
    //         lastSmaller=nums[i];
    //         maxLength=max(maxLength,count);
    //     }
    //     return maxLength;
    // }
    //Optimal Approch O(n)
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int maxLength=1;
        int count=1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:nums){
            if(st.find(it-1)==st.end()){
                int num=it;
                count=1;
                while(st.find(num+1)!=st.end()){
                    num+=1;
                    count++;
                }
            }
            maxLength=max(maxLength,count);
        }
        return maxLength;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of Longest Consecutive Sequence: " << sol.longestConsecutive(nums) << endl;
    return 0;
}