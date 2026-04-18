#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int maxSum=0;
        int leftSum=0,rightSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        maxSum=max(maxSum,leftSum);
        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[rightIndex];
            rightIndex--;
            maxSum=max(maxSum,leftSum+rightSum);
        }
        return maxSum;
    }
};
int main(){
    Solution sol;
    vector<int> cardPoints={1,2,3,4,5,6,1};
    int k=3;
    cout<<sol.maxScore(cardPoints,k)<<endl; // Output: 12
    return 0;
}