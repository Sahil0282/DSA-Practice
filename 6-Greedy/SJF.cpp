#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n=bt.size();
        int totalWt=0;
        int waitForCurrentProcess=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++){
          totalWt+=waitForCurrentProcess;
          waitForCurrentProcess+=bt[i];
        }
        return floor((double)totalWt/n);
    }
};
int main() {
    Solution sol;
    vector<int> bt{4,1,3,2};
    cout << sol.solve(bt) << endl;
    return 0;
}