#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         // Vector to store final merged intervals
//         vector<vector<int>> ans;
                
//         // If no intervals, return empty result
//         if(intervals.empty()) return ans;
//         int n=intervals.size();

//         // Sort intervals based on starting time
//         // This ensures overlapping intervals come next to each other
//         sort(intervals.begin(),intervals.end());
//         for(int i=0;i<n;){ //Instead of incrementing i normally, we jump to next non-overlapping interval
//             int start=intervals[i][0];
//             int end=intervals[i][1];// to keep track of current start and end
//             int j=i+1; //to check the intervals after the current interval
//             while(j<n && intervals[j][0]<=end){
//                 end=max(end,intervals[j][1]);// Update end to maximum ending value
//                 // This expands the merged interval
//                 j++;
//             }
//             ans.push_back({start,end});
//             i=j; //Instade of Incrementing i by one each time we move it to next non-overlapping interval
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> ans;

        // If no intervals, return empty result
        if(n == 0) return ans;
        // Sort intervals by starting time
        // So overlapping intervals come next to each other
        sort(intervals.begin(), intervals.end());
        // Take first interval as current interval
        int start = intervals[0][0];
        int end   = intervals[0][1];
        // Traverse remaining intervals
        for(int i = 1; i < n; i++) {
            // If current interval overlaps with previous
            if(intervals[i][0] <= end) {
                // Extend the current interval
                end = max(end, intervals[i][1]);
            } else {
                // No overlap → store previous interval
                ans.push_back({start, end});
                // Start tracking new interval
                start = intervals[i][0];
                end   = intervals[i][1];
            }
        }
        // Push the last merged interval
        ans.push_back({start, end});
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans=s.merge(intervals);
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
}