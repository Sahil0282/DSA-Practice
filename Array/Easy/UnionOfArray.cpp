#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
  public:
    // vector<int> findUnion(vector<int> &a, vector<int> &b) {
    //     int n1=a.size();
    //     int n2=b.size();
    //     vector<int> ans;
    //     int i=0,j=0;
    //     while(i<n1 && j<n2){
    //         if(a[i]<b[j]){
    //             if(ans.empty() || ans.back()!=a[i]) ans.push_back(a[i]);
    //             i++;
    //         }else if(b[j]<a[i]){
    //             if(ans.empty() || ans.back()!=b[j]) ans.push_back(b[j]);
    //             j++;
    //         }else{
    //             if(ans.empty() || ans.back()!=b[j]) ans.push_back(b[j]);
    //             j++;i++;
    //         }
    //     }
    //     while(i<n1){
    //         if(ans.empty() || ans.back()!=a[i]) ans.push_back(a[i]);
    //         i++;
    //     }
    //     while(j<n2){
    //         if(ans.empty() || ans.back()!=b[j]) ans.push_back(b[j]);
    //         j++;  
    //     }
    //     return ans;
    // }
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        int n=a.size();
        int m=b.size();
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            st.insert(b[i]);
        }
        vector<int> unionArr(st.begin(), st.end());
        return unionArr;
    }
    
};
int main() {
    Solution sol;
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5, 6};
    vector<int> result = sol.findUnion(a, b);
    cout << "Union of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}