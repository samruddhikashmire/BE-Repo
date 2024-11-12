#include<bits/stdc++.h>
using namespace std;


int knapsack(int W, vector<int>&weights , vector<int>&values , int n)
{
    vector<vector<int>> dp(n+1 , vector<int>(W+1 , 0));
    
    for(int i=1 ; i<=n ; i++)
    {
        for(int w=0 ; w<=W ; w++)
        {
            if(weights[i-1] <= w)
            {
                dp[i][w] = max(dp[i-1][w] , dp[i-1][w-weights[i-1]] + values[i-1]);
            }
            else
              dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
    
}

int main()
{
     int W = 50; // Capacity of the knapsack
    vector<int> weights = {10, 20, 30}; // Weights of the items
    vector<int> values = {60, 100, 120}; // Values of the items
    int n = weights.size(); // Number of items

    int max_value = knapsack(W, weights, values, n);

    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}