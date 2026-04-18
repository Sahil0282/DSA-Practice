#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // void rotate(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     vector<vector<int>> ans;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             ans[i][n-i-1]=matrix[i][j];
    //         }
    //     }
    // }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
    for(auto row:matrix){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}