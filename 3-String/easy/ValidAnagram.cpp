#include<iostream>
#include<string>
using namespace std;
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size()!=t.size()) return false;
//         unordered_map<char,int> freq;
//         for(auto ch:s){
//             freq[ch]++;
//         }
//         for(auto ch:t){
//             freq[ch]--;
//         }
//         for(auto it:freq){
//             if(it.second>0) return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        for(auto ch:t){
            freq[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    string str1="anagram";
    string str2="nagaram";
    cout<<s.isAnagram(str1,str2)<<endl;
    return 0;
}