#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int findPow(int n,int x,int m){
    long long result=1;
    for(int i=0;i<n;i++){
        if(result>m/(long long)x) return m+1;
        result*=x;
    }
    return result;
};
int NthRoot(int n, int m) {
    int low=1,high=m;
    if(m == 0 || m == 1) return m;
    while(low<=high){
        int mid=low+(high-low)/2;
        long long val=findPow(n,mid,m);
        if(val==m){
            return mid;
        }
        else if(val>m){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
};
};
int main(){
    Solution sol;
    int n=3;
    int m=27;
    cout<<sol.NthRoot(n,m);
    return 0;
}           