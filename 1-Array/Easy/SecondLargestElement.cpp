#include <iostream> 
#include <vector>
#include <limits>
using namespace std;
class Solution {
  public:
    // Brute O(n log n) + O(n)
    // int SecondLargestElement(vector<int> &arr) {
    //     sort(arr.begin(),arr.end());
    //     for(int i=arr.size()-2;i>=0;i--){
    //         if(arr[i]!=arr[i+1]) return arr[i];
    //     }
    //     return -1;
    // }
    //Better O(2N);
    // int SecondLargestElement(vector<int> &arr) {
    //     int n=arr.size();
    //     int maxElement=arr[0];
    //     int secondMax=INT_MIN;
    //     for(int i=1;i<n;i++){
    //         if(arr[i]>maxElement) maxElement=arr[i];
    //     }
    //     for(int i=0;i<n;i++){
    //         if(arr[i]>secondMax && arr[i]!=maxElement){
    //             secondMax=arr[i];
    //         }
    //     }
    //     return secondMax;
    // }
    //Optimal O(n)
    int SecondLargestElement(vector<int> &arr) {
        int n=arr.size();
        int maxElement=INT_MIN;
        int secondMax=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>maxElement){
                secondMax=maxElement;
                maxElement=arr[i];
            }else if(arr[i]>secondMax && arr[i]<maxElement){
                secondMax=arr[i];
            }
        }
        return secondMax;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "The second largest element is: " << sol.SecondLargestElement(arr) << endl;
    return 0;
}