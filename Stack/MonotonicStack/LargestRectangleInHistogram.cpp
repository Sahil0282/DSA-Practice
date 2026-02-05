#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         int maxArea=0;
//         for(int i=0;i<n;i++){
//             int smallest=INT_MAX;
//             for(int j=i;j<n;j++){
//                 smallest=min(smallest,heights[j]);
//                 count++;
//                 maxArea=max(maxArea,smallest*count);
//             }
//         }
//         return maxArea;
//     }
// };

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea=0;
//         stack<int> st;
//         vector<int> NextSmaller(n),PreviousSmaller(n);
//         for(int i=n-1;i>=0;i--){
//             while(!st.empty() && heights[st.top()]>=heights[i]){
//                 st.pop();
//             }
//             NextSmaller[i]=st.empty()?n:st.top();
//             st.push(i);
//         }
//         while(!st.empty()){
//             st.pop();
//         }
//         for(int i=0;i<n;i++){
//             while(!st.empty() && heights[st.top()]>=heights[i]){
//                 st.pop();
//             }
//             PreviousSmaller[i]=st.empty()?-1:st.top();
//             st.push(i);
//         }
//         for(int i=0;i<n;i++){
//             maxArea = max(maxArea,heights[i] * (NextSmaller[i] - PreviousSmaller[i] - 1));
//         }
//         return maxArea;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int currentElement=st.top();
                st.pop();
                int NSE=i;
                int PSE=st.empty()?-1:st.top();
                maxArea=max(maxArea,heights[currentElement]*(NSE-PSE-1));
            }
            st.push(i);
        }
        while(!st.empty()){
                int currentElement=st.top();
                st.pop();
                int NSE=n;
                int PSE=st.empty()?-1:st.top();
                maxArea=max(maxArea,heights[currentElement]*(NSE-PSE-1));
        }
        return maxArea;
    }
};
int main(){
    Solution sol;
    vector<int> heights={2,1,5,6,2,3};
    cout<<sol.largestRectangleArea(heights)<<endl; 
    return 0;
}