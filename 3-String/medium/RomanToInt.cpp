#include<iostream>
#include<string>
using namespace std;
// class Solution {
// public:
//     // int romanToInt(string s) {
//     //     unordered_map<char,int> mp={
//     //         {'I',1},{'V',5},{'X',10},
//     //         {'L',50},{'C',100},{'D',500},{'M',1000}
//     //     };
//     //     int n=s.size();
//     //     int result=0;
//     //     for(int i=0;i<n;i++){
//     //         if(i<n-1 && mp[s[i]]<mp[s[i+1]]) result=result-mp[s[i]];
//     //         else result=result+mp[s[i]];
//     //     }
//     //     return result;
//     // }
//     int romanToInt(string s) {
//         unordered_map<char,int> mp={
//             {'I',1},{'V',5},{'X',10},
//             {'L',50},{'C',100},{'D',500},{'M',1000}
//         };
//         int n=s.size();
//         int result=0;
//         int prev=0;
//         for(int i=n-1;i>=0;i--){
//             int curr=mp[s[i]];
//             if(curr<prev) result-=curr;
//             else result+=curr;
//             prev=curr;
//         }
//         return result;
//     }
// };

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                if (i < n - 1 && s[i + 1] == 'V') {
                    result += 4;
                    i++;
                } else if (i < n - 1 && s[i + 1] == 'X') {
                    result += 9;
                    i++;
                } else {
                    result += 1;
                }
            }else if(s[i]=='X'){
                if(i<n-1 && s[i+1]=='L'){
                    result+=40;
                    i++;
                }else if(i<n-1 && s[i+1]=='C'){
                    result+=90;
                    i++;
                }else{
                    result+=10;
                }
            }else if(s[i]=='C'){
                if(i<n-1 && s[i+1]=='D'){
                    result+=400;
                    i++;
                }else if(i<n-1 && s[i+1]=='M'){
                    result+=900;
                    i++;
                }else{
                    result+=10;
                }
            }
            else if(s[i]=='V') result+=5;
            else if(s[i]=='L') result+=50;
            else if(s[i]=='D') result+=500;
            else if(s[i]=='M') result+=1000;
        }
        return result;
    }
};
int main(){
    Solution s;
    string str="MCMXCIV";
    cout<<s.romanToInt(str)<<endl;
    return 0;
}