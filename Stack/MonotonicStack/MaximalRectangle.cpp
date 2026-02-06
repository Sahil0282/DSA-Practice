#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> heights){
        int n=heights.size();
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int currentIndex=st.top();
                st.pop();

                int NSE=i;
                int PSE=st.empty()?-1:st.top();
                maxArea=max(maxArea,heights[currentIndex]*(NSE-PSE-1));
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int currentIndex=st.top();
            st.pop();

            int NSE=n;
            int PSE=st.empty()?-1:st.top();
            maxArea=max(maxArea,heights[currentIndex]*(NSE-PSE-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefixSum(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                    sum+=1;
                }else{
                    sum=0;
                }
                prefixSum[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int area=largestRectangleArea(prefixSum[i]);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
int main(){
    Solution sol;
    vector<vector<char>> matrix={
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout<<sol.maximalRectangle(matrix)<<endl; // Output: 6
    return 0;
}