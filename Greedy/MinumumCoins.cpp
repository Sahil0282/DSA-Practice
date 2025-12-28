#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
		sort(coins.begin(),coins.end(),greater<>());
		int total=0;
		int n=coins.size();
		int count=0;
		int i=0;
		while(i<n){
			if(total+coins[i]<amount){
				total+=coins[i];
				count++;
			}else if(total+coins[i]==amount) return count+1;
			else{
				i++;
			}
		}
		return -1;
    }
};
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amount = 93;
    
    int result = sol.MinimumCoins(coins, amount);
    if (result != -1) {
        cout << "Minimum number of coins required: " << result << endl;
    } else {
        cout << "It's not possible to form the amount with the given coins." << endl;
    }
    return 0;
}
