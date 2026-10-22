// # Subarray Sum Equals K [Medium]

// Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum equals `k`.

// A subarray is a contiguous, non-empty sequence of elements within an array.

// ### Example 1

// **Input**
// nums = [1, 1, 1], k = 2

// **Output**
// 2

// ### Example 2

// **Input**
// nums = [1, 2, 3], k = 3

// **Output**
// 2

// ### Constraints

// - `1 <= nums.length <= 2 * 10^4`
// - `-1000 <= nums[i] <= 1000`
// - `-10^7 <= k <= 10^7`


// Code :- Using Prefix Sum + Hash map

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSubArrSum(vector<int>& Nums, int k){

    unordered_map<int, int> prefixCount;

    int prefixSum = 0;
    int totalCount = 0;

    prefixCount[0] = 1;

    for(int num : Nums){
        prefixSum += num;

        int required = prefixSum - k;

        // Count previous prefix sums that can form sum k
        if (prefixCount.find(required) != prefixCount.end()) {
            totalCount += prefixCount[required];
        }

        prefixCount[prefixSum]++;

    }

    return totalCount;

}


// Code :- Using Bruete Force

// #include<iostream>
// #include<vector>
// using namespace std;

// int countSubArrSum(vector<int>& Nums, int n, int k){

//     int count = 0;

//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += Nums[j];

//             if(sum == k){
//                 count++;
//             }
//         }
//     }

//     return count;

// }

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> Nums(n);

    for(int i=0; i<n; i++){
        cin>>Nums[i];
    }

    cout<<countSubArrSum(Nums, n, k)<<endl;

    return 0;
}