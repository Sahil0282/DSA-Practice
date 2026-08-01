#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int> ans;
    //     unordered_map<int,int> freq;
    //     for(auto it:nums){
    //         freq[it]++;
    //     }
    //     vector<pair<int,int>> vec(freq.begin(), freq.end());
    //     sort(vec.begin(),vec.end(),[](const auto& a, const auto& b){
    //         return a.second>b.second;
    //     });
    //     for(auto it:vec){
    //         if(k>0){
    //             ans.push_back(it.first);
    //             k--;
    //         }else break;
    //     }
    //     return ans;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        unordered_map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        for(auto it:freq){
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=bucket.size();i>0;i--){
            for(auto it:bucket[i]){
                res.push_back(it);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}