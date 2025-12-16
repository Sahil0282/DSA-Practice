#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canEat(vector<int>& piles, int h,int maxCap){
        int n=piles.size();
        int totalHrs=0;
        for(int i=0;i<n;i++){
            totalHrs+=ceil((double)piles[i]/(double)maxCap);
            if(totalHrs>h) return false;
        }
        return totalHrs<=h;
    }
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int low=*min_element(piles.begin(),piles.end());
    //     int high=*max_element(piles.begin(),piles.end());
    //     for(int i=low;i<=high;i++){
    //         if(canEat(piles,h,i)) return i;
    //     }
    //     return -1;
    // }
    int minEatingSpeed(vector<int>& piles, int h) {
        // int low=*min_element(piles.begin(),piles.end());
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canEat(piles,h,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> piles={3,6,7,11};
    int h=8;
    cout<<sol.minEatingSpeed(piles,h)<<endl; // Output: 4
    return 0;
}