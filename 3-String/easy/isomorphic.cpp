#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        unordered_map<char,char> freqS;
        unordered_map<char,char> freqT;
        for(int i=0;i<n;i++){
            if(freqS.find(s[i])!=freqS.end() && freqS[s[i]]!=t[i]) return false;
            if(freqT.find(t[i])!=freqT.end() && freqT[t[i]]!=s[i]) return false;
            freqS[s[i]]=t[i];
            freqT[t[i]]=s[i];
        }
        return true;
    }
};
int main(){
    Solution s;
    string str1="egg";
    string str2="add";
    cout<<s.isIsomorphic(str1,str2)<<endl;
    return 0;
}