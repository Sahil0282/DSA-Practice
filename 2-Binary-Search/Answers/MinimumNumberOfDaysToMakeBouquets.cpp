#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k,int minDay){
        int n=bloomDay.size();
        int totalBouquet=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=minDay){
                count++;
                if(count==k){
                    totalBouquet++;
                    count=0;
                }
            }else{
                count=0;
            }
        }
        return totalBouquet>=m;
    }
    // int minDays(vector<int>& bloomDay, int m, int k) {
    //     if(m>bloomDay.size()) return -1;
    //     int low=*min_element(bloomDay.begin(),bloomDay.end());
    //     int high=*max_element(bloomDay.begin(),bloomDay.end());
    //     for(int i=low;i<=high;i++){
    //         if(canMake(bloomDay,m,k,i)) return i;
    //     }
    //     return -1;
    // }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canMake(bloomDay,m,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> bloomDay={1,10,3,10,2};
    int m=3,k=1;
    cout<<sol.minDays(bloomDay,m,k)<<endl; // Output: 3
    return 0;
}