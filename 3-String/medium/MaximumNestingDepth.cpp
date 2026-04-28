#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxCount=0;
        for(auto ch:s){
            if(ch=='('){
                count++;
            }else if(ch==')'){
                maxCount=max(count,maxCount);
                count--;
            }
        }
        return maxCount;
    }
};
int main(){
    Solution s;
    string str="(1+(2*3)+((8)/4))+1";
    cout<<s.maxDepth(str)<<endl;
    return 0;
}
