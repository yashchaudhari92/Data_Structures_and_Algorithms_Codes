// # Minimum Coins Required (Coin Change)

// ## Problem

// Given an array `coins[]` of size `N` with unlimited supply of each coin, find the **minimum number of coins required** to make the target value `V`. Return `-1` if it is not possible.

// ## Example

// **Input**
// ```text
// 3 11
// 9 6 5
// ```

// **Output**
// ```text
// 2
// ```

// Here:
// - `N = 3` (number of coin denominations)
// - `V = 11` (target value)
// - `coins = [9, 6, 5]`


// Code :- 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCoinReq(vector<int>& coins, int target){

    const int INF = target + 1;     // We use 12 as a placeholder meaning "impossible or not calculated yet."   

    vector<int> dp(target + 1, INF);

    dp[0] = 0;      // dp[0] = 0? Because if the amount is zero, we don't need any coins. This is our starting point.

    // dp[amount] - The minimum number of coins needed to make that amount.

    for(int amount = 1; amount <= target; amount++){

        for(int coin : coins){
            if(coin <= amount && dp[amount - coin] != INF){
                dp[amount] = min(dp[amount], dp[amount - coin] + 1);
            }
        }
    }

    return dp[target] == INF ? -1 : dp[target];

}


int main(){
    int N, V;

    cin >> N >> V;

    vector<int> coins(N);

    for(int i=0; i<N; i++){
        cin>>coins[i];
    }

    cout<<minCoinReq(coins, V)<<endl;

    return 0;

}