#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    // Brute Force Approach O(n^2) Time Complexity and O(1) Space Complexity 
    // int lengthOfLongestSubstring(string s) {
    //     int n=s.size();
    //     int maxLen=0;
    //     for(int i=0;i<n;i++){
    //         int freq[256]={0};
    //         for(int j=i;j<n;j++){
    //             if(freq[s[j]]==1) break;
    //             maxLen=max(maxLen,j-i+1);
    //             freq[s[j]]++;
    //         }
    //     }
    //     return maxLen;
    // }

    // Optimal Approach Using Sliding Window Technique O(n) Time Complexity and O(1) Space Complexity
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLen=0;
        vector<int> hashMap(256,-1);
        int left=0,right=0;
        while(right<n){
            if(hashMap[s[right]]!=-1 && hashMap[s[right]]>=left){
                left=hashMap[s[right]]+1;
            }
            maxLen=max(maxLen,right-left+1);
            hashMap[s[right]]=right;
            right++;
        }
        return maxLen;
    }

};
int main(){
    Solution sol;
    string s = "abcabcbb";
    cout << "Length of Longest Substring Without Repeating Characters: " << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}