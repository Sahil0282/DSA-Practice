#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    // bool isValid(string s,int index,int count){
    //     if(count<0){
    //         return false;
    //     }
    //     if(index==s.size()){
    //         return (count==0);
    //     }
    //     if(s[index]=='('){
    //         return isValid(s,index+1,count+1);
    //     }else if(s[index]==')'){
    //         return isValid(s,index+1,count-1);
    //     }else{
    //         return isValid(s,index+1,count) || isValid(s,index+1,count+1) || isValid(s,index+1,count-1);
    //     }
    // }
    // bool checkValidString(string s) {
    //     return isValid(s,0,0);
    // }
    bool checkValidString(string s) {
        int min=0,max=0;
        for(auto ch:s){
            if(ch=='('){
                min++;
                max++;
            }else if(ch==')'){
                min--;
                max--;
            }else{
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        return (min==0);
    }
};
int main() {
    Solution sol;
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (sol.checkValidString(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    return 0;
}