#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int drop=0;
        // if it is Sorted and rotated then it will only have one drop 
        // for e.g 5,4,3,1,2 the drop is at 3->1 and no drop at last->first 
        //but if it was 2 1 3 4 there are two drops
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) drop++;
        }
        if(nums[n-1]>nums[0]) drop++;
        if(drop<=1) return true;
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    if (sol.check(nums)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}