#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void fn(int n,vector<string>& res,string curr,int idx){
        if(idx==n){
            res.push_back(curr);
            return;
        }
        fn(n,res,curr+'0',idx+1);
        if(curr.empty() || curr.back()!='1'){
            fn(n,res,curr+'1',idx+1);
        }
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> res;
        fn(n,res,"",0);
        return res;
    }
};
int main(){
    Solution s;
    int n=3;
    vector<string> res=s.generateBinaryStrings(n);
    for(auto i:res){
        cout<<i<<" ";
    }
}