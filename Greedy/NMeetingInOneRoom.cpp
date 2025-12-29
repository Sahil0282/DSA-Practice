#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    // int maxMeetings(vector<int>& start, vector<int>& end){
    //     vector<pair<int,int>> meetings;
    //     int n=start.size();
    //     for(int i=0;i<n;i++){
    //         meetings.push_back({end[i],start[i]});
    //     }
    //     sort(meetings.begin(),meetings.end());
    //     int lastHeld=meetings[0].first;
    //     int count=1;
    //     for(int i=1;i<n;i++){
    //         if(lastHeld<meetings[i].second){
    //             lastHeld=meetings[i].first;
    //             count++;
    //         }
    //     }
    //     return count;
    // }

    int maxMeetings(vector<int>& start, vector<int>& end){
        vector<tuple<int,int,int>> meetings;
        vector<int> ansInd;
        int n=start.size();
        for(int i=0;i<n;i++){
            meetings.push_back({end[i],start[i],i});
        }
        sort(meetings.begin(),meetings.end());
        int lastHeld=-1;
        for(auto m:meetings){
            int e=get<0>(m);
            int s=get<1>(m);
            int i=get<2>(m);
            if(s>lastHeld){
                lastHeld=e;
                ansInd.push_back(i);
            }
        }
        return ansInd.size();
    }
};
int main(){
    Solution sol;
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    int result=sol.maxMeetings(start,end);
    cout<<"Maximum number of meetings that can be held: "<<result<<endl;
    return 0;
}