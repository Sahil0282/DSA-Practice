#include<iostream>
#include<vector>
using namespace std;
// class Solution{
// public:    	
//     void countSub(vector<int>& nums,int k,int sum,int &count,int idx){
//         if(idx>=nums.size()){
//             if(sum==k){
//                 count+=1;
//             }
//             return;
//         }
//         countSub(nums,k,sum+nums[idx],count,idx+1);
//         countSub(nums,k,sum,count,idx+1);
//     }
//     int countSubsequenceWithTargetSum(vector<int>& nums, int k){
//         int count=0;
//         countSub(nums,k,0,count,0);
//         return count;
//     }
// };
class Solution{
    public:  
    int countSub(vector<int>& nums,int k,int sum,int idx){
        if(idx>=nums.size()){
            if(sum==k){
                return 1;
            }
            return 0;
        }
        int left=countSub(nums,k,sum+nums[idx],idx+1);
        int right=countSub(nums,k,sum,idx+1);
        return left+right;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	return countSub(nums,k,0,0);
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,1};
    int k=2;
    cout<<s.countSubsequenceWithTargetSum(nums,k)<<endl;
    return 0;
}