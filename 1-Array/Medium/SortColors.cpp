#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Counting sort approach O(n) time and O(1) space
    // void sortColors(vector<int>& nums) {
    //     int cnt0=0,cnt1=0,cnt2=0;
    //     int n=nums.size();
    //     for(auto it:nums){
    //         if(it==0) cnt0++;
    //         else if(it==1) cnt1++;
    //         else cnt2++;
    //     }
    //     for(int i=0;i<cnt0;i++){
    //         nums[i]=0;
    //     }
    //     for(int i=cnt0;i<cnt1+cnt0;i++){
    //         nums[i]=1;
    //     }
    //     for(int i=cnt0+cnt1;i<n;i++){
    //         nums[i]=2;
    //     }
    // }
    //Dutch National Flag Algorithm O(n) time and O(1) space
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;low++;
            }
            else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,0,2,1,1,0};
    sol.sortColors(nums);
    cout<<"Sorted colors: ";
    for(int num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}