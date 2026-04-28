#include<iostream>
#include<string>
#include<stack>
using namespace std;
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         stack<int> st;
//         string res="";
//         for(auto ch:s){
//             if(ch=='('){
//                 if(!st.empty()) res+=ch;
//                 st.push(ch);
//             }else{
//                 st.pop();
//                 if(!st.empty()) res+=ch;
//             }
//         }
//         return
//     }
// };
class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;
        string res="";
        for(auto ch:s){
            if(ch=='('){
                if(counter>0) res+=ch;
                counter++;
            }else{
                counter--;
                if(counter>0) res+=ch;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    string str="(()())(())(()(()))";
    cout<<s.removeOuterParentheses(str)<<endl;
    return 0;
}