#include <iostream>
#include <algorithm>
using namespace std;

int minCost(int cost[], int n)
{
    int dp[n];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i=2; i<n; i++)
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

int main()
{
    int n;
    cout<<"number of steps: ";
    cin>>n;
    int cost[n];
    cout<<"cost of each step: ";
    for (int i=0; i<n; i++)
        cin>>cost[i];
    int result = minCost(cost, n);
    cout<<"Min cost to reach the top: "<<result<<endl;
    return 0;
}
