#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int maxProfit=0;
        for(int i=1;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};
int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl; // Output: Maximum profit: 5
    return 0;
}