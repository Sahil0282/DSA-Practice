#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    // string frequencySort(string s) {
    //     unordered_map<char,int> freq;
    //     for(auto ch:s){
    //         freq[ch]++;
    //     }
    //     vector<pair<char,int>> ans(freq.begin(),freq.end());
    //     sort(ans.begin(),ans.end(),[](auto &a,auto &b){
    //         return a.second>b.second;
    //     });
    //     string res="";
    //     for(auto it:ans){
    //         res+=string(it.second,it.first);
    //         // res+=append(it.second,it.first)
    //     }
    //     return res;
    // }

    // string frequencySort(string s) {
    //     unordered_map<char,int> freq;
    //     for(auto ch:s){
    //         freq[ch]++;
    //     }
    //     sort(s.begin(),s.end(),[&](auto &a,auto &b){
    //         if(freq[a] == freq[b]) return a < b;
    //         return freq[a]>freq[b];
    //     });
    //     return s;
    // }

    // string frequencySort(string s) {
    //     unordered_map<char,int> freq;
    //     for(auto ch:s){
    //         freq[ch]++;
    //     }
    //     priority_queue<pair<int,char>> pq;
    //     for(auto it:freq) pq.push({it.second,it.first});
    //     string result="";
    //     while(!pq.empty()){
    //         auto [count,ch]=pq.top();
    //         pq.pop();
    //         result+=string(count,ch);
    //     }
    //     return result;
    // }

    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto ch:s){
            freq[ch]++;
        }
        vector<vector<char>> buckets(s.size()+1);
        for(auto it:freq){
            buckets[it.second].push_back(it.first);
        }
        string result="";
        for(int i=s.size()-1;i>=0;i--){
            for(auto ch:buckets[i]){
                result.append(i,ch);
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    string str="tree";
    cout<<s.frequencySort(str)<<endl;
    return 0;
}