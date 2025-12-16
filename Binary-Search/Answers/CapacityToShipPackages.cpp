#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canShip(vector<int>& weights, int days,int maxCap){
        int n=weights.size();
        int totalDays=1;
        int currentLoad=weights[0];
        for(int i=1;i<n;i++){
            if(currentLoad+weights[i]<=maxCap){
                currentLoad+=weights[i];
            }else{
                currentLoad=weights[i];
                totalDays++;
            }
        }
        return totalDays<=days;

    }
    // int shipWithinDays(vector<int>& weights, int days) {
    //     int low=*max_element(weights.begin(),weights.end());
    //     int high=accumulate(weights.begin(),weights.end(),0);
    //     for(int i=low;i<=high;i++){
    //         if(canShip(weights,days,i)) return i;
    //     }
    //     return -1;
    // }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShip(weights,days,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    cout<<sol.shipWithinDays(weights,days)<<endl; // Output: 15
    return 0;
}