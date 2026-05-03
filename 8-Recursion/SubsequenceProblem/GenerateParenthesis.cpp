#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void fn(int open,int close,int n,vector<string>& res,string curr){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)
            fn(open+1,close,n,res,curr+'(');
        if(close<open)
            fn(open,close+1,n,res,curr+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        fn(0,0,n,res,"");
        return res;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    vector<string> res=s.generateParenthesis(n);
    for(auto i:res)
        cout<<i<<" ";
}