#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n=arr.size();
        int m=indices.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int count=0;
            int currentEle=arr[indices[i]];
            for(int j=indices[i]+1;j<n;j++){
                if(arr[j]>currentEle){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> arr={3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices={0,5};
    vector<int> result=sol.count_NGE(arr,indices);
    for(int val:result){
        std::cout<<val<<" "; 
    }
    std::cout<<std::endl;
    return 0;
}