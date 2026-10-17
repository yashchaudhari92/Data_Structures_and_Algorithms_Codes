#include<iostream>
#include<vector>
using namespace std;

int knapSackTabu(vector<int> val, vector<int> wt, int w, int n){

    // Initialize the dp with 0
    vector<vector<int>> dp(n+1, vector<int>(w + 1, 0));

    // Here i = no of Items
    // And j = capacity of knapsack

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j){
                // 1 is Include & 2 is Exclude
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // To print the DP
    for(int i= 0; i<n+1; i++){
        for(int j= 0; j<w+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][w];
}

int main(){

    vector<int> val = { 15, 14, 10, 45, 30};
    vector<int> wt = { 2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    cout<< knapSackTabu(val, wt, w, n)<<endl;

    return 0;
}