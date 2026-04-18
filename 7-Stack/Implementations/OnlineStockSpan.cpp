#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
class StockSpanner {
public:
    vector<int> stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(!stock.empty()){
            stock.push_back(price);
            int count=1;
            for(int i=stock.size()-1;i>0;i--){
                if(price>=stock[i-1]){
                    count++;
                }else{
                    break;
                }
            }
            return count;
        }
        else{
            stock.push_back(price);
            return 1;
        }
    }
};
*/
class StockSpanner {
public: 
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() { 
        idx=-1;
        st = stack<pair<int,int>>();
    }
    int next(int price) {
        idx++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans=idx-(st.empty()?-1:st.top().second);
        st.push({price,idx});
        return ans;
    }
};
int main() {
    StockSpanner spanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << spanner.next(price) << " ";
    }
    cout << endl;
    return 0;
}
