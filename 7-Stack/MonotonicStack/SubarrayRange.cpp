#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int n=nums.size();
//         long long sum=0;
//         for(int i=0;i<n;i++){
//             int largest=nums[i];
//             int smallest=nums[i];
//             for(int j=i;j<n;j++){
//                 largest=max(largest,nums[j]);
//                 smallest=min(smallest,nums[j]);
//                 sum+=largest-smallest;
//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:
    vector<int> NGE(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PGE(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSE(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        vector<int> nge=NGE(nums);
        vector<int> pge=PGE(nums);
        vector<int> nse=NSE(nums);
        vector<int> pse=PSE(nums);

        for(int i=0;i<n;i++){
            int leftMax=(i-pge[i]);
            int rightMax=(nge[i]==-1?n:nge[i])-i;
            long long maxContribution=1ll*leftMax*rightMax*nums[i];

            int leftMin=(i-pse[i]);
            int rightMin=(nse[i]==-1?n:nse[i])-i;
            long long minContribution=1ll*leftMin*rightMin*nums[i];

            sum+=maxContribution-minContribution;
        }   
        return sum;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    cout<<sol.subArrayRanges(nums)<<endl; // 4
    return 0;
}