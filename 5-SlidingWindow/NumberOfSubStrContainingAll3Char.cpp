#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int numberOfSubstrings(string s) {
    //     int n=s.size();
    //     int maxCount=0;
    //     for(int i=0;i<n;i++){
    //         vector<char> freq(3,0);
    //         for(int j=i;j<n;j++){
    //             freq[s[j]-'a']=1;
    //             if(freq[0]+freq[1]+freq[2]==3){
    //                 maxCount+=1;
    //             } 
    //         }
    //     }
    //     return maxCount;
    // }

    // int numberOfSubstrings(string s) {
    //     int n=s.size();
    //     int maxCount=0;
    //     vector<int> freq(3,0);
    //     int r=0,l=0;
    //     while(r<n){
    //         freq[s[r]-'a']++;
    //         while(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
    //             maxCount+=n-r;
    //             freq[s[l]-'a']--;
    //             l++;
    //         }
    //         r++;
    //     }
    //     return maxCount;
    // }

    int numberOfSubstrings(string s) {
        int n=s.size();
        int maxCount=0;
        vector<int> freq(3,-1);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']=i;
            if(freq[0]!=-1 && freq[1]!=-1 && freq[2]!=-1){
                maxCount+=(1+min(min(freq[0],freq[1]),min(freq[1],freq[2])));
            }
        }
        return maxCount;
    }

};
int main(){
    Solution sol;
    string s="abcabc";
    cout<<sol.numberOfSubstrings(s)<<endl; // Output: 10
    return 0;
}