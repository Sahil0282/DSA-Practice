#include<iostream>
#include<vector>
using namespace std;
//Type - 1
//when Row Number And Column Number is Given and we have to find and return that element 
/*
class solution{
    public:
        int generate(int Rows,int Col) {
            int res=1;
            for(int i=0;i<COl;i++){
                res=res*(n-i);
                res=res/(i+1);
            }
            return res;
        }
}
*/

// Type - 2
//when row number is given and we have to print the entire row
/*
//Brute Force O(n*r)
class solution{
    public:
        int gen(int Rows,int Col) {
            int res=1;
            for(int i=0;i<COl;i++){
                res=res*(n-i);
                res=res/(i+1);
            }
            return res;
        }
        void generate(int n) {
            int ans=1;
            cout<<ans<<'/t';
            for(int i=0;i<n;i++){
                cout<<gen(n,i)<<'/t;
            }
        }
}
#Optimal
class solution{
    public:
        void generate(int n) {
            int ans=1;
            cout<<ans<<'\t';
            for(int i=0;i<n;i++){
                ans=ans*(n-i);
                ans=ans/(i);
                cout<<ans<<'\t';
            }
        }
}
*/

// Type - 3
//when only row number is given and you have to print the entire rectangle
class Solution {
public:
    vector<int> generateRow(int Row){
        vector<int> ans;
        long long res=1;
        ans.push_back(res);
        for(int i=1;i<Row;i++){
            res=res*(Row-i);
            res=res/i;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
int main(){
    int numRows;
    cin>>numRows;
    Solution s;
    vector<vector<int>> ans=s.generate(numRows);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}