#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
       stack<int> st;
       for(auto ch:s){
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }else{
            if(st.empty()) return false;
            char it=st.top();
            st.pop();

            if((it=='(' && ch==')') ||
            (it=='[' && ch==']') ||
            (it=='{' && ch=='}')){
                continue;
            }else{
                return false;
            }
        } 
    }
    return st.empty();
    }
};
int main(){
    Solution sol;
    string s = "{[()]}";
    if(sol.isValid(s)){
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }
    return 0;
}