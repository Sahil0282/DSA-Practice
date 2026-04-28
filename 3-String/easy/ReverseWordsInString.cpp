#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string res = "", temp = "";
        reverse(s.begin(), s.end());
        for (auto ch : s) {
            if (ch != ' ') {
                temp += ch;
            } else {
                if (temp != "") {
                    reverse(temp.begin(), temp.end());
                    if (res != "")
                        res += " ";
                    res += temp;
                    temp = "";
                }
            }
        }
        if (temp != "") {
            reverse(temp.begin(), temp.end());
            if (res != "")
                res += " ";
            res += temp;
            temp = "";
        }
        return res;
    }
};
int main() {
    Solution s;
    string str = "  hello world!  ";
    cout << s.reverseWords(str) << endl; //Output: "world! hello"
    return 0;
}
