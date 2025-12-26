#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        int n=bills.size();
        for(auto bill:bills){
            if(bill==5) five++;
            else if(bill==10){
                if(five==0) return false;
                five--;
                ten++;
            }else{
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                }else if(five>=3) {
                    five-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> bills={5,5,10,10,20};
    cout<<sol.lemonadeChange(bills)<<endl; // Output: 1 (true)
    return 0;
}