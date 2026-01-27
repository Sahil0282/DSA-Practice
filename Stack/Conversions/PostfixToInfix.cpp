#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    string postToInfix(string postExp) {
        stack<string> st;
        for(auto ch:postExp){
            if(isalpha(ch)){
                // string temp="";
                // temp+=ch;
                // st.push(temp);
                st.push(string(1,ch));
            }else{
                string SecondChar=st.top();
                st.pop();
                string FirstChar=st.top();    
                st.pop();
                st.push("("+FirstChar+ch+SecondChar+")");
            }
        }
        return st.top();
    }
};
int main(){
    Solution sol;
    string postExp="ab+cde+**";
    cout<<sol.postToInfix(postExp)<<endl;
    return 0;
}
//     string postExp="ab+cde+**";