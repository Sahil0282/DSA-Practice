#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int n=asteroids.size();
//         stack<int> st;
//         for(int i=0;i<n;i++){
//             int curr=asteroids[i];
//             bool alive=true;
//             while(!st.empty() && st.top()>0 && curr<0){
//                 int top=st.top();
//                 if(abs(top)<abs(curr)){
//                     st.pop();
//                 }else if(abs(top)>abs(curr)){
//                     alive=false;
//                     break;
//                 }else{
//                     st.pop();
//                     alive=false;
//                     break;
//                 }
//             }
//             if(alive){
//                 st.push(curr);
//             }
//         }
//         vector<int> ans(st.size());
//         for (int i = ans.size() - 1; i >= 0; i--) {
//             ans[i] = st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                    st.pop_back();
                }
                if(!st.empty() && st.back()==abs(asteroids[i])){
                    st.pop_back();
                }else if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};
int main(){
    Solution sol;
    vector<int> asteroids={5,10,-5};
    vector<int> result=sol.asteroidCollision(asteroids);
    for(int val:result){
        cout<<val<<" ";
    }
    return 0;
}