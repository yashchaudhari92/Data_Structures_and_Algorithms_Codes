// Problem Statement :
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You must write an algorithm that runs in O(n) time 
// and without using the division operation.

// Friends Sharing Lunch, But Skipping Their Own!
// Imagine 4 friends sitting together at lunch. Each friend brings their own lunch, but they all decide to share and taste everyone’s 
// lunch except their own. So, Friend 1 eats the lunch of Friends 2, 3, and 4. Friend 2 eats the lunch of Friends 1, 3, and 4, and so on. 
// Similarly, in this problem, you calculate the product of all elements in the array except the current element, just like each friend 
// tasting all the lunches except their own.

// Example 1:
// Input: nums = [1, 2, 3, 4]
// Output: [24, 12, 8, 6]

// Example 2:
// Input: nums =[-1, 1, 0, -3, 3]
// Output: [0, 0, 9, 0, 0]


// Code :- 

#include<iostream>
#include<vector>
using namespace std;

void prodExceptSelf(vector<int>& nums){

    int n = nums.size();

    vector<int>ans(n, 1);

    for(int i=1; i<n; i++){
        // Prefix product calculation
        ans[i] = ans[i-1] * nums[i-1];
    }


    // Multiply prefix with suffix and then update suffix by multiplying them with nums[i].
    int suffix = nums[n-1];
    for(int i=n-2; i>=0; i--){
        
              // Prefix * Suffix
        ans[i] = ans[i] * suffix;
        suffix = suffix * nums[i];
    }

    int m = ans.size();

    for(int i=0; i<m; i++){
        cout << ans[i] << " ";
    }

    cout << endl;

}


int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    prodExceptSelf(nums);
    return 0;
}