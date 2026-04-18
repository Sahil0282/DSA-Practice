#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        int start=0,end=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        start=newInterval[0];
        end=newInterval[1];
        while(i<n && intervals[i][0]<=end){
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        ans.push_back({start,end});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }   
        return ans;     
    }
};
int main(){
    Solution sol;
    vector<vector<int>> intervals{{1,3},{6,9}};
    vector<int> newInterval{2,5};
    vector<vector<int>> updatedIntervals=sol.insert(intervals,newInterval);
    for(auto interval: updatedIntervals){
        cout<<"["<<interval[0]<<","<<interval[1]<<"] ";
    }
    cout<<endl;
    return 0;
}