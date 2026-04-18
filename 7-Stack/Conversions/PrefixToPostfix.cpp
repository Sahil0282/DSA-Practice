#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string prefixToPostfix(string s) {
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            if(isalnum(ch)){
                st.push(string(1,ch));
            }else{
                string first=st.top();
                st.pop();
                string second=st.top();
                st.pop();
                st.push(first+second+ch);
            }
        }
        return st.top();
    }
};
int main(){
    Solution sol;
    string prefixExp="*+ab*+cde";
    cout<<sol.prefixToPostfix(prefixExp)<<endl; // ab+cd*e+*
    return 0;
}