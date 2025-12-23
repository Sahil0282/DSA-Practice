#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution {
public:
    // string minWindow(string s, string t) {
    //     int n=s.size();
    //     int m=t.size();
    //     int minLen=INT_MAX;
    //     int startIndex=-1;
    //     for(int i=0;i<n;i++){
    //         vector<int> freq(256,0);
    //         int count=0;
    //         for(auto ch:t) freq[ch]++;
    //         for(int j=i;j<n;j++){
    //             if(freq[s[j]]>0) count++;
    //             freq[s[j]]--;

    //             if(count==m){
    //                 if(j-i+1<minLen)
    //                 {
    //                     minLen=(j-i+1);
    //                     startIndex=i;
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     if(startIndex==-1) return "";
    //     return s.substr(startIndex,minLen);
    // }
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int minLen=INT_MAX;
        int right=0,left=0;
        int startIndex=-1;
        unordered_map<char,int> freq;
        for(auto ch:t) freq[ch]++;
        int count=0;
        while(right<n){
            if(freq[s[right]]>0) count++;
            freq[s[right]]--;

            while(count==m){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    startIndex=left;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0) count--;
                left++;
            }

            right++;
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minLen);
    }
};
int main(){
    Solution sol;
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<sol.minWindow(s,t)<<endl; // Output: "BANC"
    return 0;
}