#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<vector<int>> ans;
    //     int n=intervals.size();
    //     int i=0;
    //     sort(intervals.begin(), intervals.end());
    //     for(int i=0;i<n;){
    //         int start=intervals[i][0];
    //         int end=intervals[i][1];
    //         int j=i+1;
    //         while(j<n && intervals[j][0]<=end){
    //             end=max(intervals[j][1],end);
    //             j++;
    //         }
    //         ans.push_back({start,end});
    //         i=j;
    //     }
    //     return ans;
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        sort(intervals.begin(), intervals.end());
        int start=intervals[i][0];
        int end=intervals[i][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }else{
             ans.push_back({start,end});
             start=intervals[i][0];
             end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mergedIntervals=sol.merge(intervals);
    for(auto interval: mergedIntervals){
        cout<<"["<<interval[0]<<","<<interval[1]<<"] ";
    }
    cout<<endl;
    return 0;
}