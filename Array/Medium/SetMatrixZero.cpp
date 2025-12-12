#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    /* Brute Force Approach:
       Mark entire row & column using -1 whenever a zero is found, then convert all -1 to 0. */

    // void markRow(vector<vector<int>>& matrix,int i){
    //     int m=matrix[0].size();
    //     for(int j=0;j<m;j++){
    //         if(matrix[i][j]!=0){
    //             matrix[i][j]=-1;
    //         }
    //     }
    // }
    // void markCol(vector<vector<int>>& matrix,int j){
    //     int n=matrix.size();
    //     for(int i=0;i<n;i++){
    //         if(matrix[i][j]!=0){
    //             matrix[i][j]=-1;
    //         }
    //     }
    // }
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(matrix[i][j]==0){
    //                 markRow(matrix,i);
    //                 markCol(matrix,j);
    //             }
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(matrix[i][j]==-1){
    //                 matrix[i][j]=0;
    //             }
    //         }
    //     }
    // }

    /* Better Approach:
       Use two extra arrays to mark rows and columns that must become zero, then update matrix. */

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     vector<int> row(n,0);
    //     vector<int> col(m,0);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(matrix[i][j]==0){
    //                 col[j]=1;
    //                 row[i]=1;
    //             }
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(row[i]==1 || col[j]==1){
    //                 matrix[i][j]=0;
    //             }
    //         }
    //     }
    // }

    /* Optimal Approach:
       Use first row and first column as zero markers to achieve O(1) extra space. */

    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};
int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    sol.setZeroes(matrix);
    cout << "Matrix after setting zeros:" << endl;
    for(const auto& row : matrix){
        for(const auto& val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}