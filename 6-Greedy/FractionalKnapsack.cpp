#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n=val.size();
        double maxValue=0;
        long long cap=capacity;
        vector<pair<double,int>> items;
        for(int i=0;i<n;i++){
            items.push_back({((double)val[i]/wt[i]),i});
        }
        sort(items.begin(),items.end(),greater<>());
        for(int i=0;i<n;i++){
            int idx=items[i].second;
            if(wt[idx]<=cap){
                maxValue+=val[idx];
                cap-=wt[idx];
            }
            else{
                maxValue+=val[idx]*((double)cap/wt[idx]);
                break;
            }
        }
        return maxValue;
    }
};
int main(){
    Solution sol;
    vector<long long> val={60,100,120};
    vector<long long> wt={10,20,30};
    long long capacity=50;
    cout<<sol.fractionalKnapsack(val,wt,capacity)<<endl; // Output: 240
    return 0;
}