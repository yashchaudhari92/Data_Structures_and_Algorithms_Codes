// It is a variation of 0-1 KnapSack or same as 0-1 KnapSack 
// In 0-1 knapsack we have given the values and its weights but in these we have given only the values
// So nums[i-1] = values = weights

#include<iostream>
#include<vector>
using namespace std;

bool targetSumSubset(vector<int> nums, int target){
    // Storage + Meaning and initialization
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    // nums[i-1] = value = weight
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1] <= j){
                // 1st is for include & 2nd is for exclude
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target] = target;
}

int main(){

    vector<int> nums = { 4, 2, 7, 1, 3};
    int target = 10;

    cout<< targetSumSubset(nums, target) <<endl;

    return 0;
}