// # Problem Statement: Unique Paths

// A delivery robot is placed on a rectangular grid with `m` rows and `n` columns. The robot always starts at position `(0,0)`, which represents the top-left corner of the grid.

// The goal of the robot is to reach the bottom-right corner of the grid, i.e., cell `(m-1, n-1)`.

// The robot can only move either to the **Right** or **Down** at any step.

// You need to determine how many unique paths the robot can take to reach its destination.

// ### Examples

// **Example 1**

// Input:
// ```text
// m = 3, n = 2
// ```

// Output:
// ```text
// 3
// ```

// Explanation: From the top-left corner, there are 3 ways to reach the bottom-right corner:

// 1. Right → Down → Down
// 2. Down → Down → Right
// 3. Down → Right → Down

// **Example 2**

// Input:
// ```text
// m = 3, n = 7
// ```

// Output:
// ```text
// 28
// ```


// Code using DP :- 

#include<iostream>
#include<vector>
using namespace std;


// m - row && n - column
long long uniquePaths(int m, int n){

    vector<vector<long long>> dp(m, vector<long long>(n, 1));

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    return dp[m-1][n-1];

}

int main(){
    int m, n;
    cin>>m>>n;

    cout<<uniquePaths(m, n)<<endl;

    return 0;
}


// Code using Recursion :- 


#include <iostream>
using namespace std;

int countPaths(int row, int col, int m, int n) {

    // Base case: reached destination
    if (row == m - 1 && col == n - 1) {
        return 1;
    }

    // Base case: outside the grid
    if (row >= m || col >= n) {
        return 0;
    }

    // Move down
    int down = countPaths(row + 1, col, m, n);

    // Move right
    int right = countPaths(row, col + 1, m, n);

    return down + right;
}

int main() {
    int m, n;
    cin >> m >> n;

    cout << countPaths(0, 0, m, n) << '\n';

    return 0;
}
