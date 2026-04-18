#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    // ---------------- BRUTE FORCE (O(n^2)) ----------------
    // vector<int> leaders(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> ans;
    //
    //     for (int i = 0; i < n; i++) {
    //         bool flag = true;
    //         for (int j = i + 1; j < n; j++) {
    //             if (arr[i] < arr[j]) {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if (flag) ans.push_back(arr[i]);
    //     }
    //
    //     return ans;
    // }

    // ---------------- OPTIMIZED (O(n)) ----------------
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        int maxi = arr[n - 1];
        ans.push_back(maxi);

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> arr={16,17,4,3,5,2};
    vector<int> result=sol.leaders(arr);
    for(int num:result){
        cout<<num<<" ";
    }
    return 0;
}