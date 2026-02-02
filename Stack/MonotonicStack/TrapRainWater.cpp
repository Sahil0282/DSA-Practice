#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        vector<int> prefixMax(n),suffixMax(n);
        prefixMax[0]=height[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int leftMax=prefixMax[i],rightMax=suffixMax[i];
            if(height[i]<leftMax && height[i]<rightMax){
                total+=min(leftMax,rightMax)-height[i];

            }
        }
        return total;
    }   
};
int main(){
    Solution sol;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(height)<<endl; 
    return 0;
}