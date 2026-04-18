#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
class Solution {
public:
    int prio(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        return -1;
    }
    string infixToPrefix(string s) {
        stack<char> st;
        string result="";
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                s[i]=')';
            }else if(s[i]==')'){
                s[i]='(';
            }
        }
        for(auto ch:s){
            if(isalnum(ch)){
                result+=ch;
            }
            else if(ch=='('){
                st.push('(');
            }else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }else{
                if(ch=='^'){
                    while(!st.empty() && prio(st.top())>=prio(ch)){
                        result+=st.top();
                        st.pop();
                    }
                }
                else{
                    while(!st.empty() && prio(st.top())>prio(ch)){
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
        reverse(result.begin(),result.end());
        return result;
    }
};
int main(){
    Solution sol;
    string infix = "(A-B/C)*(A/K-L)";
    string prefix = sol.infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl; // Output: *-A/BC-/AKL
    return 0;
}