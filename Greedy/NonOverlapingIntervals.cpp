#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     int n=intervals.size();
    //     int count=0;
    //     sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
    //         return a[1]<b[1]; 
    //     });
    //     int i=1;
    //     int end=intervals[0][1];
    //     while(i<n){
    //         if(intervals[i][0]<end) count++;
    //         else{
    //             end=intervals[i][1];
    //         }
    //         i++;
    //     }
    //     return count;
    // }

    //N meetings version
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=1;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1]; 
        });
        int end=intervals[0][1];
        for (int i = 1; i < n; i++){
            if(intervals[i][0]>=end) {
                count++;
                end=intervals[i][1];
            }   
        }
        return (n-count);
    }
};
int main(){
    Solution sol;
    vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};
    int result=sol.eraseOverlapIntervals(intervals);
    cout<<"Minimum number of intervals to remove to make non-overlapping: "<<result<<endl;
    return 0;
}