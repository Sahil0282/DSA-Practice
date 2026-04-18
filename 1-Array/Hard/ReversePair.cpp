#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int countPair=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]>(2*nums[j])) countPair++;
//             }
//         }
//         return countPair;
//     }
// };
class Solution {
public:
    long long count = 0; // stores total reverse pairs

    void merge(vector<int> &nums,int low,int mid,int high){
        vector<int> temp;
        int left = low, right = mid + 1;

        // standard merge of two sorted halves
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);

        for(int i = low; i <= high; i++)
            nums[i] = temp[i - low];
    }

    int countPair(vector<int> &nums,int low,int mid,int high){
        int j = mid + 1;
        int cnt = 0;

        // count reverse pairs BEFORE merging
        for(int i = low; i <= mid; i++){
            // move j forward while condition holds (j never resets)
            while(j <= high && (long long)nums[i] > 2LL * nums[j])
                j++;

            cnt += (j - (mid + 1)); // number of valid right elements
        }

        return cnt;
    }

    void mergeSort(vector<int> &nums,int low,int high){
        if(low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);

        count += countPair(nums,low,mid,high); // count before merge
        merge(nums,low,mid,high);
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,3,2,3,1};
    cout<<s.reversePairs(nums)<<endl;
    return 0;
}