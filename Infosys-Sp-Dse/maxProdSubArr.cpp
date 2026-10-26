// Maximum Product SubArray

// This is particularly relevant because a candidate's published Infosys Specialist Programmer interview experience includes a maximum-product subarray question. 

// Given an array of integers, find the maximum product of any non-empty contiguous subarray.

// Example input
// 4
// 2 3 -2 4


// Expected output
// 6

// Code :- Using Modified Kadane's Algorithm
// Tracking minimum and maximum Product


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long maxProdSubArr(vector<long long>& arr, int n){
    long long currMax = arr[0];
    long long currMin = arr[0];
    long long maxAns = arr[0];

    for(int i=1; i<n; i++){
        long long x = arr[i];

        // Importan :- Save the previous values
        long long oldMax = currMax;
        long long oldMin = currMin;

        currMax = max({x, x * oldMax, x * oldMin});
        currMin = min({x, x * oldMax, x * oldMin});

        maxAns = max(maxAns, currMax);
    }

    return maxAns;
}


int main(){

    int n;
    cin >> n;

    if(n == 0) return 0;

    vector<long long> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout<<maxProdSubArr(arr, n)<<endl;

    return 0;
}

