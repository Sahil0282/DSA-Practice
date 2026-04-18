#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canAssign(vector<int> &nums, int m,int maxPages){
        int current=nums[0];
        int n=nums.size();
        int std=1;
        for(int i=1;i<n;i++){
            if(current+nums[i]<=maxPages){
                current+=nums[i];
            }else{
                std++;
                current=nums[i];
            }
        }
        return std<=m;
    }
    // int findPages(vector<int> &nums, int m)  {
    //     int high=accumulate(nums.begin(),nums.end());
    //     int low=*max_element(nums.begin(),nums.end());
    //     for(int i=low;i<=high;i++){
    //         if(canAssign(nums,m,i)) return i;
    //     }
    //     return -1;
    // }

    int findPages(vector<int> &nums, int m)  {
        if (m > nums.size()) return -1;
        int high=accumulate(nums.begin(),nums.end(),0);
        int low=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canAssign(nums,m,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> books={12,34,67,90};
    int m=2;
    cout<<sol.findPages(books,m);
    return 0;
}