#include <iostream>
#include <vector>
#include <unordered_map>
/*
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int Xor=0;
            for(int j=i;j<n;j++){
                Xor^=nums[j];
                if(Xor==k) count++;
            }
        }
        return count;
    }
};
*/
class Solution{
public:

    int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        int Xor=0;
        int count=0;
        unordered_map<int,int> preXor;
        preXor[0]=1;
        for(int i=0;i<n;i++){
            Xor^=nums[i];
            int rem=Xor^k;
            if(preXor.find(rem)!=preXor.end()){
                count+=preXor[rem];
            }
            preXor[Xor]++;
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> nums={4,2,2,6,4};
    int k=6;
    cout<<s.subarraysWithXorK(nums,k)<<endl; // 4
    return 0;
}