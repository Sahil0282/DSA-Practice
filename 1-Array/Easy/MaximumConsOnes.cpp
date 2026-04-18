#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maxCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                maxCount=max(maxCount,count);
                count=0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = sol.findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive ones: " << result << endl;
    return 0;
}