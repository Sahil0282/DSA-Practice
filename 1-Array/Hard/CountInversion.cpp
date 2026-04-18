#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//    long long int numberOfInversions(vector<int> nums) {
//         int n=nums.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]>nums[j]){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    long long count=0;
    void mergeSort(vector<int> &nums,int low,int mid,int high){
        vector<int> ans;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                ans.push_back(nums[left++]);
            }else{
                count+=(mid-left+1);
                ans.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            ans.push_back(nums[left++]);
        }
        while(right<=high){
            ans.push_back(nums[right++]);
        }
        int index=0;
        for(int i=low;i<=high;i++){
            nums[i]=ans[index++];
        }
    }
    void merge(vector<int> &nums,int low,int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        merge(nums,low,mid);
        merge(nums,mid+1,high);
        mergeSort(nums,low,mid,high);
    }
   long long int numberOfInversions(vector<int> nums) {
        count=0;
        int n=nums.size();
        if(n==0) return 0;
        merge(nums,0,n-1);
        return count;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.numberOfInversions(nums);
}