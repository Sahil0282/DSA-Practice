#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
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
        int low=0,high=(n*m)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    if(obj.searchMatrix(matrix,target)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}