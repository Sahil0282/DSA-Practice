#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int mySqrt(int x) {
    //     int ans=0;
    //     if (x <= 1) return x;
    //     for(int i=0;i<x;i++){
    //         if((long long)i*i<=x) ans=i;
    //         else break;
    //     }
    //     return ans;
    // }

    int mySqrt(int x) {
        int low=0,high=x;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((long long)mid*mid<=x){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    cout<<"Square root of "<<x<<" is "<<sol.mySqrt(x)<<endl;
    return 0;
}