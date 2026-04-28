#include<iostream>
#include<string>
using namespace std;
// class Solution {
// public:
//     bool isPali(string s){
//         int n=s.size();
//         int l=0,r=n-1;
//         while(l<=r){
//             if(s[l]!=s[r]) return false;
//             l++;r--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         int n=s.size();
//         string res="";
//         int maxLen=0;
//         for(int i=0;i<n;i++){
//             string temp="";
//             for(int j=i;j<n;j++){
//                 temp+=s[j];
//                 if(isPali(temp)){
//                     if(maxLen<j-i+1){
//                         maxLen=j-i+1;
//                         res=temp;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    void expand(string &s,int left,int right,string &res){
        int n=s.size();
        while(left>=0 && right<s.size() && s[left]==s[right]){
            if(right-left+1>res.size()){
                res=s.substr(left,right-left+1);
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            expand(s,i,i,res);
            expand(s,i,i+1,res);
        }
        return res;
    }
};
int main(){
    Solution s;
    string str="babad";
    cout<<s.longestPalindrome(str)<<endl;
    return 0;
}