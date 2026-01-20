#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    //     int n=Arrival.size();
    //     int platform=0;
    //     for(int i=0;i<n;i++){
    //         int count=1;
    //         for(int j=i+1;j<n;j++){
    //             if((Arrival[i]>=Arrival[j] && Arrival[i]<=Departure[j]) || (Arrival[j]>=Arrival[i] && Arrival[j]<=Departure[i])) count++;
    //         }
    //         platform=max(platform,count);
    //     }
    //     return platform;
    // }

    int findPlatform(vector<int> &Arrival, vector<int> &Departure)
    {
        int n = Arrival.size();
        int platform = 0;
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int i = 0, j = 0, count = 0;
        while (i < n)
        {
            if (Arrival[i] <= Departure[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            platform = max(platform, count);
        }
        return platform;
    }
};
int main()
{
    Solution obj;

    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << obj.findPlatform(Arrival, Departure);

    return 0;
}
