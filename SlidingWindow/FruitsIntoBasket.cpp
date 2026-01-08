#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    // int totalFruit(vector<int>& fruits) {
    //     int n=fruits.size();
    //     int maxCount=0;
    //     for(int i=0;i<n;i++){
    //         set<int> st;
    //         for(int j=i;j<n;j++){
    //             st.insert(fruits[j]);
    //             if(st.size()<=2){
    //                 maxCount=max(maxCount,j-i+1);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     }
    //     return maxCount;
    // }

    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxCount=0;
        int left=0,right=0;
        unordered_map<int,int> bucket;
        while(right<n){
            bucket[fruits[right]]++;
            if(bucket.size()>2){
                bucket[fruits[left]]--;
                if(bucket[fruits[left]]==0) bucket.erase(fruits[left]);
                left++;
            }
            maxCount=max(maxCount,right-left+1);
            right++;
        }
        return maxCount;
    }
};
int main(){
    Solution sol;
    vector<int> fruits={1,2,1,2,3,2,2,1};
    cout<<sol.totalFruit(fruits)<<endl;
    return 0;
}