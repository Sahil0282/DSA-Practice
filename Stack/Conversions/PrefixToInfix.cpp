#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string prefixToInfix(string s) {
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
                st.push("("+first+ch+second+")");
            }
        }
        return st.top();
    }
};
int main(){
    Solution sol;
    string prefixExp="*+ab*+cde";
    cout<<sol.prefixToInfix(prefixExp)<<endl; // ((a+b)*(c+(d*e))
    return 0;
}