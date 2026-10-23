// # Subarray Sums Divisible by K [Medium]

// Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.

// A subarray is a contiguous part of an array.

// ### Example

// **Input**
// nums = [4, 5, 0, -2, -3, 1]
// k = 5

// **Output**
// 7


// **Explanation:** There are 7 subarrays with a sum divisible by `k = 5`:

// 1. `[4, 5, 0, -2, -3, 1]`
// 2. `[5]`
// 3. `[5, 0]`
// 4. `[5, 0, -2, -3]`
// 5. `[0]`
// 6. `[0, -2, -3]`
// 7. `[-2, -3]`

// ### Constraints

// - `1 <= nums.length <= 3 * 10^4`
// - `-10^4 <= nums[i] <= 10^4`
// - `2 <= k <= 10^4`


// Code :- Using Prefix Sum (Remainder Count) + Hash 

// We are storing the remainder along with it's frequency

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subArrSumDivByK(vector<int>& nums, int k){
    
    unordered_map<int, int> remainderCount;

    int prefixSum = 0; 
    int totalCount = 0;

    remainderCount[0] = 1;

    for(int num : nums){
        prefixSum += num;

        // Normalize remainder for negative sums
        int remainder = ((prefixSum % k) + k ) % k;

        // Previous matching remainders give valid subarrays
        totalCount += remainderCount[remainder];

        remainderCount[remainder]++;
    }

    return totalCount;
}

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout<<subArrSumDivByK(nums, k)<<endl;

    return 0;

}


// Code using Bruete Force Approach:- 

// #include<iostream>
// #include<vector>
// using namespace std;

// int subArrSumDivByK(vector<int>& nums, int n, int k){ 
//     int Count = 0;

//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += nums[j];

//             if(sum % k == 0){
//                 Count++;
//             }
//         }
//     }

//     return Count;
// }

// int main(){

//     int n, k;
//     cin >> n >> k;

//     vector<int> nums(n);

//     for(int i=0; i<n; i++){
//         cin >> nums[i];
//     }

//     cout<<subArrSumDivByK(nums, n, k)<<endl;

//     return 0;

// }