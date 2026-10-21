// # Minimum Swaps to Make Array Even-Odd (Summer Array)

// ## Problem

// Given an array of size `N`, an array is considered a **summer array** if all even values are on one side and all odd values are on the other side.

// You can swap adjacent elements.

// Return the **minimum number of adjacent swaps** required to make the array a summer array.

// ## Example

// **Input**
// ```text
// 6
// 1 2 3 4 5 6
// ```

// **Output**
// ```text
// 3
// ```


// Code :- Solution using Greedy Counting approach

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int countSwaps(vector<int>& arr, int n){

    int swapCount;

    int evenSeen = 0;
    int oddSeen = 0;

    int evenFirstSwap = 0;
    int oddFirstSwap = 0;

    for(int i=0; i<n; i++){
        if(arr[i]%2 == 0){
            evenSeen++;
            evenFirstSwap += oddSeen;
        } else {
            oddSeen++;
            oddFirstSwap += evenSeen;
        }
    }

    return swapCount = min(oddFirstSwap, evenFirstSwap);
}

int main(){
    int n;
    cin>> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<countSwaps(arr, n)<<endl;

    return 0;
}