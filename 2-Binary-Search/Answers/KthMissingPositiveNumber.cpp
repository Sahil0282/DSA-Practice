#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int findKthPositive(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     for(int i=0;i<n;i++){
    //         if(arr[i]<=k) k++;
    //         else break;
    //     }
    //     return k;
    // }

    // int findKthPositive(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     int low=1,high=n-1;
    //     while(low<=high){
    //         int mid=low+(high-low)/2;
    //         if(arr[mid]-(mid+1)>k) high=mid-1;
    //         else low=mid+1;
    //     }
    //     // return arr[high]+(k-(arr[high]-(high+1)));
    //     // after solving above
    //     return high+k+1;
    // }

    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int counter=0;
        int index=0;
        int last=arr[n-1];
        for(int i=1;i<=last;i++){
            if(arr[index]!=i){
                counter++;
                if(counter==k) return i;
            }else if(arr[index]==i) index++;
            if(index>n-1){
                last-=counter;
                return last+k;
            }
        }
        return -1;
    }
};
int main(){
    Solution sol;
    vector<int> arr={2,3,4,7,11};
    int k=5;
    cout<<sol.findKthPositive(arr,k)<<endl; // Output: 9
    return 0;
}