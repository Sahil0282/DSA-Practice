#include <string>
#include <iostream>
#include <vector>
class Solution
{
public:
    string strCmp(string str, string largestPrefix)
    {
        string prefix = "";
        for (int i = 0; i < min(str.size(), largestPrefix.size()); i++)
        {
            if (str[i] != largestPrefix[i])
                break;
            prefix += str[i];
        }
        return prefix;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        int n = strs.size();
        string prefix = strs[0];
        for (int i = 1; i < n; i++)
        {
            prefix = strCmp(strs[i], prefix);
            if (prefix.empty())
                return "";
        }
        return prefix;
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}

/*
class Solution{
    public:
        string longestCommonPrefix(vector<string>& str){
            string ans="";
            for(int i=0;i<str[0].size();i++){
                char ch=str[0][i];
                for(int j=1;j<str.size();j++){
                    if(i==str[j].size() || str[j][i]!=ch) return str[0].substr(0,i);
                }
            }
            return str[0];
        }
};

class Solution{
    public:
        string longestCommonPrefix(vector<string>& str){
            if(str.empty()) return "";
            sort(str.begin(),str.end());
            string first=str[0];
            string last=str[str.size()-1];
            string ans="";
            for(int i=0;i<min(first.size(),last.size());i++){
                if(first[i]!=last[i]) break;
                ans+=first[i];
            }
            return ans;
        }
};
*/