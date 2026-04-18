// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// class Solution {
// public:
// // int kDistinctChars(int k, string &str)
// // {
// //     int n=str.size();
// //     int charCount=0;
// //     int maxCount=0;
// //     for(int i=0;i<n;i++){
// //         int freq[26]={0};
// //         int charCount=0;
// //         for(int j=i;j<n;j++){
// //             if(freq[str[j]-'a']==0 && charCount==k) break;
// //             else if(freq[str[j]-'a']==0 && charCount<k){
// //                 freq[str[j]-'a']++;
// //                 charCount++;
// //             }
// //             maxCount=max(maxCount,j-i+1);
// //         }
// //     }   
// //     return maxCount;
// // };
// int kDistinctChars(int k, string &str)
// {
//     int n=str.size();
//     int charCount=0;
//     int maxCount=0;
//     vector<int> freq(26,0);
//     int l=0,r=0;
//     while(r<n){
//         while(freq[str[r]-'a']==0 && charCount==k){
//             freq[str[l]-'a']--;
//             if(freq[str[l]-'a']==0) charCount--;
//             l++;
//         }
//         if(freq[str[r]-'a']==0) charCount++;

//         freq[str[r]-'a']++;
//         maxCount=max(maxCount,r-l+1);
//         r++;
//     }
//     return maxCount;
// }
// };
// int main()
// {
//     Solution sol;
//     string str = "eceba";
//     int k = 2;
//     int result = sol.kDistinctChars(k, str);
//     cout << "The length of the longest substring with at most " << k << " distinct characters is: " << result << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n=s.size();
        int maxCount=0;
        int l=0,r=0;
        unordered_map<char,int> freq;
        while(r<n){
            freq[s[r]]++;
            while(freq.size()>k){
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            maxCount=max(maxCount,r-l+1);
            r++;
        }
        return maxCount;
    }
};
int main()
{
    Solution sol;
    string str = "eceba";
    int k = 2;
    int result = sol.kDistinctChar(str, k);
    cout << "The length of the longest substring with at most " << k << " distinct characters is: " << result << endl;
    return 0;
}