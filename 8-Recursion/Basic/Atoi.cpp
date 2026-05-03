#include<iostream>
#include<string>
#include<climits>
using namespace std;
class Solution {
public:
    long recursion(string &s,int i,long result,int sign){
        if(i>=s.size() || !isdigit(s[i])) return sign*result;
        int digit=s[i]-'0';
        if(result>(INT_MAX-digit)/10) return sign==1?INT_MAX:INT_MIN;
        return recursion(s,i+1,result*10+digit,sign);
    }
    int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        return recursion(s,i,0,sign);
    }
};
int main(){
    Solution s;
    cout<<s.myAtoi("   -42")<<endl;
    cout<<s.myAtoi("4193 with words")<<endl;
    cout<<s.myAtoi("words and 987")<<endl;
    cout<<s.myAtoi("-91283472332")<<endl;
    return 0;
}