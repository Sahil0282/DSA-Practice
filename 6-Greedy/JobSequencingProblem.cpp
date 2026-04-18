#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {
        int n = Jobs.size();
        sort(Jobs.begin(), Jobs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] > b[2]; });
        int maxi = INT_MIN;
        for (auto it : Jobs)
        {
            maxi = max(maxi, it[1]);
        }
        int jobCnt = 0;
        int profit = 0;
        vector<int> slot(maxi + 1, -1);
        for (int i = 0; i < n; i++)
        {
            for (int day = Jobs[i][1]; day >= 1; day--)
            {
                if (slot[day] == -1)
                {
                    slot[day] = Jobs[i][0];
                    jobCnt++;
                    profit += Jobs[i][2];
                    break;
                }
            }
        }
        return {jobCnt, profit};
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> Jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> ans = obj.JobScheduling(Jobs);
    cout << ans[0] << " " << ans[1];
    return 0;
}