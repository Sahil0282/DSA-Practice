#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    // brute force is use nested loop
    
    //this is better approch 
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     for(int i=0;i<n;i++){
    //         if(matrix[i][0]<=target && matrix[i][m-1]>=target){
    //             int low=0,high=m-1;
    //             while(low<=high){
    //                 int mid=low+(high-low)/2;
    //                 if(matrix[i][mid]==target) return true;
    //                 else if(matrix[i][mid]>target) high=mid-1;
    //                 else low=mid+1;
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }

};
int main(){
    Solution obj;
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;
    if(obj.searchMatrix(matrix,target)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}