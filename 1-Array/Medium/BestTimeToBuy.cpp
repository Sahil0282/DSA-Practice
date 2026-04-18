#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Brute Force Approach O(n^2)
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     int maxProfit=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             maxProfit=max(maxProfit,prices[j]-prices[i]);
    //         }
    //     }
    //     if(maxProfit<0) return 0;
    //     return maxProfit;
    // }
    // Optimal Approach O(n) Space O(1)
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
int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    cout<<sol.maxProfit(prices)<<endl; // Output: 5
    return 0;
}