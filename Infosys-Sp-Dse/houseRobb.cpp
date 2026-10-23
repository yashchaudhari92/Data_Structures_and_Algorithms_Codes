// # House Robber / Stickler Thief

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. The only constraint stopping you from robbing each of them is that adjacent houses have security systems connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.

// Given an integer array `nums` representing the amount of money in each house, return the maximum amount of money you can rob tonight without alerting the police.

// ### Example

// **Input**
// nums = [1, 2, 3, 1]

// **Output**
// 4

// **Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).

// Total amount you can rob = `1 + 3 = 4`.


// Code :- Using Dynamic Programming Concept

// Remember in problem like this identify first how many choices we have, in this problem we have 2 choices 
// either we can robb it or we can skip it.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums, int n){

    if(n == 1){
        return nums[0];
    }

    vector<int> dp(n+1);
    
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++){
        int robCurrent = nums[i] + dp[i-2];
        int skipCurrent = dp[i-1];

        dp[i] = max(robCurrent, skipCurrent);

    }

    return dp[n-1];
}


int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout<<rob(nums, n)<<endl;

    return 0;

}