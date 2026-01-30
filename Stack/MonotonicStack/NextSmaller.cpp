#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> arr={4,5,2,10,8};
    vector<int> result=sol.nextSmallerElements(arr);
    for(int val:result){
        cout<<val<<" "; // Output: 2 2 -1 8 -1
    }
    cout<<endl;
    return 0;
}