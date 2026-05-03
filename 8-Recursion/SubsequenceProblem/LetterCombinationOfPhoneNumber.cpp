#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    void letterComb(string &str,string ans,vector<string> &res,unordered_map<char,string>& mapp,int idx){
        if(idx==str.size()){
            res.push_back(ans);
            return;
        }
        char digit=str[idx];
        for(auto it:mapp[digit]){
            letterComb(str,ans+it,res,mapp,idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        vector<string> res;
        string ans;
        unordered_map<char,string> mapp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        letterComb(digits,ans,res,mapp,0);
        return res;
    }
};
int main(){
    Solution s;
    string digits="23";
    vector<string> res=s.letterCombinations(digits);
    for(auto i:res){
        cout<<i<<" ";
    }
}