#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:

    // count the the maxFreq of char in window (which we can cosider main char) and after subtracting from window we will get the number of characher that need to be chang and according to that grow or shrink the window
    // int characterReplacement(string s, int k) {
    //     int n=s.size();
    //     int maxLen=0;
    //     int maxFreq=0;
    //     for(int i=0;i<n;i++){
    //         vector<int> freq(26,0);
    //         maxFreq=0;
    //         for(int j=i;j<n;j++){
    //             freq[s[j]-'A']++;
    //             maxFreq=max(maxFreq,freq[s[j]-'A']);
    //             if((j-i+1)-maxFreq<=k){
    //                 maxLen=max(maxLen,j-i+1);
    //             }
    //         }
    //     }
    //     return maxLen;
    // }

    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        int maxFreq=0;
        int left=0,right=0;
        unordered_map<char,int> freq;
        while(right<n){
            freq[s[right]]++;
            maxFreq=max(maxFreq,freq[s[right]]);
            if((right-left+1)-maxFreq>k){
                freq[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};
int main(){
    Solution sol;
    string s="AABABBA";
    int k=1;
    cout<<sol.characterReplacement(s,k)<<endl;
    return 0;
}