#include<iostream>
#include<vector>
using namespace std;

int knapSackMemo(vector<int>val, vector<int>wt, int w, int n, vector<vector<int>>& dp ){

    if(n == 0 || w == 0){
        return 0;
    }

    // Before moving forward first check dp already have a value or not
    if(dp[n][w] != -1) {
        return dp[n][w];
    }

    int itemVal = val[n-1];
    int itemWt = wt[n-1];

    if(itemWt <= w){
        // Include
        int ans1 = knapSackMemo(val, wt, w-itemWt, n-1, dp) + itemVal;

        // Exclude
        int ans2 = knapSackMemo(val, wt, w, n-1, dp);

        // Store in DP at correct place
        dp[n][w] = max(ans1, ans2);
    } else{
        // Exclude directly
        dp[n][w] = knapSackMemo(val, wt, w, n-1, dp);
    }

    return dp[n][w];

}

int main(){

    vector<int> val = { 15, 14, 10, 45, 30};
    vector<int> wt = { 2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    // Created a 2D DP of size n+1, and w+1
    vector<vector<int>> dp(n+1, vector<int>(w + 1, -1));

    cout<< knapSackMemo(val, wt, w, n, dp)<<endl;

    return 0;
}