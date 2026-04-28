#include<iostream>
#include<string>
using namespace std;
// class Solution {
// public:
//     int myAtoi(string s) {
//         int n=s.size();
//         int sign=1;
//         int result=0;
//         int i=0;
//         while(i<n && s[i]==' ') i++;
//         if(i<n && (s[i]=='+' || s[i]=='-')){
//             if(s[i]=='-') sign=-1;
//             i++;
//         }
//         while(i<n && isdigit(s[i])){
//             int digit=s[i]-'0';
//             if(result>(INT_MAX-digit)/10){
//                 return (sign==1)?INT_MAX:INT_MIN;
//             }
//             result=result*10+digit;
//             i++;
//         }
//         return result*sign;
//     }
// };

class Solution {
public:
    int fn(string s,int result,int sign,int i){
        if(i>=s.size() || !isdigit(s[i])) return result*sign;
        if(result>(INT_MAX-(s[i]-'0'))/10){
            return (sign==1)?INT_MAX:INT_MIN;
        }
        return fn(s,result*10+(s[i]-'0'),sign,i+1);  
    }
    int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        int result=0;
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        return fn(s,0,sign,i);
    }
};
int main(){
    Solution s;
    string str="-42";
    cout<<s.myAtoi(str)<<endl;
    return 0;
}