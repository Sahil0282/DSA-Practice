#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        map<vector<int>,vector<string>> hashMap;
        for(auto s:strs){
            vector<int> res(26);
            for(auto c:s){
                res[c-'a']++;
            }
            hashMap[res].push_back(s);
        }
        for(auto it:hashMap){
            ans.push_back(it.second);
        }
        return ans;

        // vector<vector<string>> ans;
        // int n=strs.size();
        // unordered_map<string,vector<string>> hashMap;
        // for(auto s:strs){
        //     string key=s;
        //     sort(key.begin(),key.end());
        //     hashMap[key].push_back(s);
        // }
        // for(auto it:hashMap){
        //     ans.push_back(it.second);
        // }
        // return ans;
    }
};
int main(){
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    cout << "Grouped Anagrams:" << endl;
    for(const auto& group : result){
        for(const auto& word : group){
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}