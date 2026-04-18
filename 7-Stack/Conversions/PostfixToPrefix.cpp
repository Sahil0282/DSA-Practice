#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string postToPre(string postfix) {
        stack<string> st;
        for(auto ch:postfix){
            if(isalnum(ch)){
                st.push(string(1,ch));
            }else{
                string second=st.top();
                st.pop();
                string first=st.top();
                st.pop();
                st.push(ch+first+second);
            }
        }
        return st.top();
    }
};
int main(){
    Solution sol;
    string postfixExp="ab+cd*e+*";
    cout<<sol.postToPre(postfixExp)<<endl; // *+ab*+cde
    return 0;
}