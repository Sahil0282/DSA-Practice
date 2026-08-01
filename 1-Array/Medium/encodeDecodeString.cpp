#include<iostream>
#include<string>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string encodeStr="";
        for(auto it:strs){
            encodeStr+=to_string(it.size())+"#"+it;
        }
        return encodeStr;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int target=0;
        string temp="";
        int i=0;
        while(i<s.size()){
            if(s[i]!='#'){
                target = target * 10 + (s[i] - '0');
                i++;
            }else{
                i++;
                while(target>0){
                    temp+=s[i];
                    target--;
                    i++;
                }
                ans.push_back(temp);
                temp="";
                target=0;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> strs = {"hello","world"};
    string encoded = s.encode(strs);
    cout << "Encoded: " << encoded << endl;
    vector<string> decoded = s.decode(encoded);
    cout << "Decoded: ";
    for(auto str:decoded){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}