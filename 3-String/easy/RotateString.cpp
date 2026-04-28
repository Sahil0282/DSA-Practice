#include <string>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n=s.size();
//         int m=goal.size();
//         if(m!=n) return false;
//         // return (s+s).contains(goal);
//         return (s+s).find(goal)!=string::npos;
//     }
// };
class Solution {
public:
    string rotation(string s,int n){
        string temp="";
        for(int i=0;i<n;i++){
            temp+=s[i];
        }
        return s.substr(n,s.size()-n)+temp;
    }
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++){
            string str=rotation(s,i+1);
            if(str==goal) return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    string str1="abcde";
    string str2="cdeab";
    cout<<s.rotateString(str1,str2)<<endl;
    return 0;
}