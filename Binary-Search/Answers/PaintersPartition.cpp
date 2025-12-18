#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int> &boards, int k, int maxLength){
        int n=boards.size();
        int painters=1;
        int currentLength=0;
        for(int i=0;i<n;i++){
            if(currentLength+boards[i]<=maxLength){
                currentLength+=boards[i];
            }else{
                painters++;
                currentLength=boards[i];
            }
        }
        return painters<=k;
    }
    // int paintersPartition(vector<int> &boards, int k) {
    //     int low=*max_element(boards.begin(),boards.end());
    //     int high=accumulate(boards.begin(),boards.end(),0);
    //     for(int i=low;i<=high;i++){
    //         if(isPossible(boards,k,i)) return i;
    //     }
    //     return -1;
    // }

    int paintersPartition(vector<int> &boards, int k) {
        int low=*max_element(boards.begin(),boards.end());
        int high=accumulate(boards.begin(),boards.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(boards,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
int main(){
    Solution sol;
    vector<int> boards={10,20,30,40};
    int k=2;
    cout<<sol.paintersPartition(boards,k);
    return 0;
}