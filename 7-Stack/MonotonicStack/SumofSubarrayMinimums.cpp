#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n=arr.size();
//         long long sum=0;
//         int mod=(int)(1e9+7);
//         for(int i=0;i<n;i++){
//             int minEle=arr[i];
//             for(int j=i;j<n;j++){
//                 minEle=min(minEle,arr[j]);
//                 sum=(sum+minEle)%mod;
//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        int mod=(int)(1e9+7);
        vector<int> nse=findNSE(arr);
        vector<int> pse=findPSE(arr);
        for(int i=0;i<n;i++){
            int howManyFromLeft=i-pse[i];
            int howManyFromRight=nse[i]-i;
            long long freq=(howManyFromLeft*howManyFromRight*1ll);
            int contribution=(freq*arr[i]*1ll)%mod;
            sum=(sum+contribution)%mod;
        }
        return sum;
    }
};
int main(){
    Solution sol;
    vector<int> arr={3,1,2,4};
    int result=sol.sumSubarrayMins(arr);
    std::cout<<result<<std::endl;
    return 0;
}