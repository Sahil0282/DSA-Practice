#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxRow(vector<vector<int>>& mat,int col){
        int n=mat.size();
        int m=mat[0].size();
        int maxEle=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(maxEle<mat[i][col]){
                maxEle=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=maxRow(mat,mid);
            int left=(mid-1>=0)?mat[row][mid-1]:-1;
            int right=(mid+1<m)?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<right) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};
int main(){
    Solution sol;
    vector<vector<int>> mat = {
        {1, 4, 3, 6, 5},
        {16, 41, 23, 22, 6},
        {15, 17, 24, 21, 7},
        {14, 18, 19, 20, 10},
        {13, 14, 11, 10, 9}
    };
    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak Element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    return 0;
}