#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    // int findMedian(vector<vector<int>>&matrix) {
    //   vector<int> ans;
    //   int n=matrix.size();
    //   int m=matrix[0].size();
    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         ans.push_back(matrix[i][j]);
    //     }
    //   }
    //   sort(ans.begin(),ans.end());
    //   return ans[(n*m)/2];
    // }

    int howManySmall(vector<vector<int>>&matrix,int target){
        int n=matrix.size();
        int count=0;
        for(int i=0;i<matrix.size();i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
        }
        return count;
    }
    int findMedian(vector<vector<int>>&matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++) low=min(low,matrix[i][0]);
        for(int i=0;i<n;i++)high=max(high,matrix[i][m-1]);
        int req=(n*m)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            int smallerCount=howManySmall(matrix,mid);
            if(smallerCount<=req) low=mid+1;
            else high=mid-1;
        }return low;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> matrix={{1,3,5},{2,6,9},{3,6,9}};
    cout<<obj.findMedian(matrix)<<endl;
    return 0;
}