#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
  public: 
  // int rowWithMax1s(vector < vector < int >> & mat) {
  //     int n=mat.size();
  //     int m=mat[0].size();
  //     int count=0;
  //     int maxCount=0;
  //     int rowIndex=-1;
  //     for(int i=0;i<n;i++){
  //       count=0;
  //       for(int j=0;j<m;j++){
  //         count+=mat[i][j];
  //       }
  //       if(count>maxCount){
  //         maxCount=count;
  //         rowIndex=i;
  //       }
  //     }
  //     return rowIndex;
  // }
  
  int BS(vector<int> mat){
    int n=mat.size();
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
      int mid=low+(high-low)/2;
      if(mat[mid]==1) {
        ans=mid;
        high=mid-1;
      }else low=mid+1;
    }
    return ans;
  }  
  int rowWithMax1s(vector < vector < int >> & mat) {
      int n=mat.size();
      int m=mat[0].size();
      int count=0;
      int maxCount=0;
      int rowIndex=-1;
      for(int i=0;i<n;i++){
          int ans=BS(mat[i]);
          if(ans>-1){
            count=m-ans;
            if(count>maxCount){
              maxCount=count;
              rowIndex=i;
            }
          }
      }
      return rowIndex;
  }
};
int main(){
    Solution obj;
    vector<vector<int>> mat={{0, 0, 0, 1},
                              {0, 1, 1, 1},
                              {1, 1, 1, 1},
                              {0, 0, 0, 0}};
    cout<<obj.rowWithMax1s(mat);
    return 0;
}