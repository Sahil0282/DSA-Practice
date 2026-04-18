#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int candy(vector<int>& ratings) {
    //     int n=ratings.size();
    //     vector<int> candies(n,1);
    //     for(int i=1;i<n;i++){
    //         if(ratings[i-1]<ratings[i]){
    //             candies[i]=candies[i-1]+1;

    //         }
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         if(ratings[i]>ratings[i+1]){
    //             candies[i]=max(candies[i],candies[i+1]+1);
    //         }
    //     }
    //     return accumulate(candies.begin(),candies.end(),0);
    // }

    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1,i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                i++;
            }
            if(down>=peak){
                sum+=down-peak+1;
            }
        }
        return sum;
    }
};
int main(){
    Solution sol;
    vector<int> ratings{1,2,87,87,87,2,1};
    cout<<sol.candy(ratings);
    return 0;
}
