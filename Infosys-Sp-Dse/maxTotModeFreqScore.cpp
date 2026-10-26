// Maximum Total Mode Frequency Score

// You are given an array a[1...N] and an integer K. You must partition the array into exactly K non-empty contiguous groups. The score of a group is defined as the frequency of its most frequent element (i.e., the mode frequency of that group).

// Your task is to find the maximum possible total mode-frequency score across all K groups.
// Input format
// - The first line contains an integer N, denoting the size of the array.
// - The second line contains an integer K, denoting the number of contiguous groups.
// - Each of the next N lines contains an integer describing a[i].

// Approach :- 

// This is a dynamic programming (DP) problem.

// Define:
//         dp[g][i] = Maximum score for the first i elements using g groups.

// To calculate the answer, consider where the final group starts. If it starts at index \(j\), its elements are a[j...i-1].

// Then:
//         dp[g][i] = max(dp[g-1][j] + modeFreq(j, i-1));

// dp[g][i]

// Don't worry about the notation yet. It simply means:
// - g = how many groups we have made.
// - i = how many elements from the beginning we have used.

// For example:
// - dp[1][3] means the best score for the first 3 elements using 1 group.
// - dp[2][7] means the best score for all 7 elements using 2 groups. This is our final answer.

// // Here, modeFreq(j, i-1) means the highest frequency of any value in that segment.

// // The final answer is dp[K][N].


// Constraints
// 1. 1 <= N <= 500
// 2. 1 <= K <= N
// 3. 1 <= a[i] <= 10**5


// Code :- 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    // Step 2: Find the score of every possible group
    vector<vector<int>> cost(N, vector<int>(N, 0));

    // Remember: l and r are used to find the score of every possible contiguous group.
    for(int l=0; l<N; l++){
        vector<int> freq(100001, 0);
        int maxFreq = 0;

        for (int r = l; r < N; r++) {
            freq[arr[r]]++;

            maxFreq = max(maxFreq, freq[arr[r]]);
            cost[l][r] = maxFreq;
        }
    }

    // Step 3: Create the DP table
    const int NEG_INF = -1000000000;

    vector<vector<int>> dp(K+1, vector<int>(N + 1, NEG_INF));

    dp[0][0] = 0;

    // Most Confusing Part
    // Step 4: Try making 1, 2, ... K groups
    for (int g = 1; g <= K; g++) {
        for (int i = g; i <= N; i++) {
            for (int j = g - 1; j < i; j++) {

                if (dp[g - 1][j] != NEG_INF) {
                    int score = dp[g - 1][j] + cost[j][i - 1];
                    dp[g][i] = max(dp[g][i], score);
                }
            }
        }
    }

    // Step 5: Print the answer
    cout << dp[K][N] << endl;

    return 0;
}