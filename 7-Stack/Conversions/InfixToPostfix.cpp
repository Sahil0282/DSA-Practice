#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        return -1;
    }
    string infixToPostfix(string s) {
        stack<char> st;
        string result="";
        for(auto ch:s){
            if(isalnum(ch)){
                result+=ch;
            }else if(ch=='('){
                st.push('(');
            }else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else{
                if(ch=='^'){
                    while(!st.empty() && priority(st.top())>priority(ch)){
                        result+=st.top();
                        st.pop();
                    }
                }
                else{
                    while(!st.empty() && priority(st.top())>=priority(ch)){
                        result+=st.top();
                        st.pop();
                    }
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};
int main(){
    Solution sol;
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = sol.infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;// Expected Output: "abcd^e-fgh*+^*+i-"
    return 0;
}