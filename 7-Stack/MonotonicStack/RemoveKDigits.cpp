#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {

        // Stack to maintain digits in increasing order
        stack<char> st;
        int n = num.size();

        // Traverse each digit of the number
        for (int i = 0; i < n; i++) {

            // Remove previous bigger digits if current digit is smaller
            // and we still have removals left
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            // Push current digit into stack
            st.push(num[i]);
        }

        // If removals are still left, remove digits from the end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // If all digits are removed
        if (st.empty()) return "0";

        // Build result from stack (will be in reverse order)
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Reverse to restore correct order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        // Return final answer
        return res.empty() ? "0" : res;
    }
};
int main(){
    Solution sol;
    string num = "1432219";
    int k = 3;
    cout << sol.removeKdigits(num, k) << endl; // Output: "1219"
    return 0;
}