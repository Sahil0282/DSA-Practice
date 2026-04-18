#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Brute Force O(2N) time and O(N) space
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> pos;
    //     vector<int> neg;
    //     int n=nums.size();
    //     for(auto it:nums){
    //         if(it>0){
    //             pos.push_back(it);
    //         }else if(it<0){
    //             neg.push_back(it);
    //         }
    //     }
    //     int index=0;
    //     for(int i=0;i<n/2;i++){
    //         nums[index++]=pos[i];
    //         nums[index++]=neg[i];
    //     }
    //     return nums;
    // }
    //Optimal O(N) time and O(N) space
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pos=0;
        int neg=1;
        for(auto it:nums){
            if(it>0) {
                ans[pos]=it;
                pos+=2;
            }else if(it<0){
                ans[neg]=it;
                neg+=2;
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> nums={3,1,-2,-5,2,-4};
    vector<int> result=obj.rearrangeArray(nums);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}