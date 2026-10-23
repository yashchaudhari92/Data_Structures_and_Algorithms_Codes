// # House Robber II

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


// Here we have two cases:

// Case 1: Exclude the last house

// Consider houses from index 0 to n - 2.
// robLinear(nums, 0, n - 2);

// Case 2: Exclude the first house

// Consider houses from index 1 to n - 1.
// robLinear(nums, 1, n - 1);


// Code :- Without using full Dp

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int robLinear(vector<int>& nums, int start, int end){
    int prev2 = 0;
    int prev1 = 0;

    for(int i=start; i<=end; i++){
        int robCurrent = nums[i] + prev2;
        int skipCurrent = prev1;

        int current = max(robCurrent, skipCurrent);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int rob(vector<int>& nums, int n){
    if(n == 1){
        return nums[0];
    }

    int case1 = robLinear(nums, 0, n-2);
    int case2 = robLinear(nums, 1, n-1);

    return max(case1, case2);
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
