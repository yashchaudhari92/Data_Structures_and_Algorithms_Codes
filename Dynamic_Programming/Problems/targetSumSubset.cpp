// It is a variation of 0-1 KnapSack or same as 0-1 KnapSack 
// In 0-1 knapsack we have given the values and its weights but in these we have given only the values
// So nums[i-1] = values = weights


#include<iostream>
#include<vector>
using namespace std;

bool targetSumSubset(vector<int> nums, int target){

    int n = nums.size();

    // Create DP table
    vector<vector<bool>> dp(
        n+1, vector<bool>(target+1, false)
    );

    // Base condition: Target 0 is always possible
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    // Fill DP table
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= target; j++){

            if(nums[i-1] <= j){

                // Include OR Exclude
                dp[i][j] =
                    dp[i-1][j-nums[i-1]] ||
                    dp[i-1][j];

            }
            else{

                // Exclude only
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

int main(){

    vector<int> nums = {4, 2, 7, 1, 3};

    int target = 10;

    if(targetSumSubset(nums, target)){
        cout << "Target Sum Possible" << endl;
    }
    else{
        cout << "Target Sum Not Possible" << endl;
    }

    return 0;
}
