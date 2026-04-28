#include <string>
#include <iostream>
#include <vector>
class Solution {
public:
    string strCmp(string str,string largestPrefix){
        string prefix="";
        for(int i=0;i<min(str.size(),largestPrefix.size());i++){
            if(str[i]!=largestPrefix[i]) break;
            prefix+=str[i];
        }
        return prefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n=strs.size();
        string prefix=strs[0];
        for(int i=1;i<n;i++){
            prefix=strCmp(strs[i],prefix);
            if(prefix.empty()) return "";
        }
        return prefix;
    }
};
int main(){
    Solution s;
    vector<string> strs={"flower","flow","flight"};
    cout<<s.longestCommonPrefix(strs)<<endl;
    return 0;
}