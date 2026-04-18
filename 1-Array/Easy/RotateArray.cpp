#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //FOR LEFT ROTATE BY 1:
    // vector<int> rotateArray(vector<int>& arr, int n) {
    //     int first=arr[0];
    //     for(int i=1;i<n;i++){
    //         arr[i-1]=arr[i];
    //     }
    //     arr[n-1]=first;
    //     return arr;
    // };
    //FOR RIGHT ROTATE BY 1:
    vector<int> rotateArray(vector<int>& arr, int n) {
        int last=arr[n-1];
        for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
        }
        arr[0]=last;
        return arr;
    };
};
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();     
    vector<int> rotatedArr = sol.rotateArray(arr, n);
    cout << "Rotated Array: ";
    for (int num : rotatedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
