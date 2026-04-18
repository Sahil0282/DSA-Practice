#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     int n=s.size();
    //     int m=g.size();
    //     sort(s.begin(),s.end()); // we have to make sure that smaller cookie must go to child with smaller greed
    //     sort(g.begin(),g.end());
    //     if(n==0 || m==0) return 0;
    //     int maxCount=0;
    //     int i=0,j=0;
    //     while(i<m && j<n){
    //         if(s[j]>=g[i]){
    //             i++;
    //             j++;
    //             maxCount++;
    //         }else{
    //             j++;
    //         }
    //     }
    //     return maxCount;
    // }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i])i++;
            j++;
        }
        return i;
    }
};
int main(){
    Solution sol;
    vector<int> g={1,2,3};
    vector<int> s={1,1};
    cout<<sol.findContentChildren(g,s)<<endl; // Output: 1
    return 0;
}