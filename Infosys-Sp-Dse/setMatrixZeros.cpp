// Problem statement :

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// 0-1 Matrix Problem : Hotel Maintenance

// Imagine a hotel where rooms are arranged in a grid, like a 0-1 matrix. If a room has a major issue (marked as 0), 
// the entire row and column must be closed for repairs. Instead of manually tracking, a smart system updates all affected rooms automatically,
// just like how we modify a 0-1 matrix to set entire rows and columns to zero when a 0 is found. 
// This helps manage problems efficiently without affecting other rooms.


// Example 1:
// Input: matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]


// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


// ##Naive Approach

// Using an Extra List to Track Zero Positions :

// Find all positions in the matrix where 0 appears and store their indexes (row, col) in a list.
// Then, iterate through the stored indexes and set the corresponding rows and columns to 0.

// 1. Identify Zero Positions:
// Traverse the entire matrix to find all positions where the value is 0.
// Store these positions in a list (vector of pairs).

// 2. Mark Rows and Columns for Zeroing:
// For each stored position (x, y), set all elements in row x to 0.
// Similarly, set all elements in column y to 0.

// 3. Update the Matrix:
// After processing all stored positions, the matrix will be updated with the required zeroes.


// Code :-

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void setZeros(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    vector<pair<int, int>> position;

    // Find index of all 0's and push it in positions list.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                position.push_back({i,j});
            }
        }
    }

    for(int i=0; i<position.size(); i++){

        int x = position[i].first;
        int y = position[i].second;

        // Zero the entire row x
        for (int i = 0; i < m; i++) {
            matrix[x][i] = 0;
        }

        // Zero the entire column y
        for (int i = 0; i < n; i++) {
            matrix[i][y] = 0;
        }
    }

    cout<<"------Output-------"<<endl;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j] << " ";
        }

        cout<<endl;
    }
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    setZeros(matrix);

    return 0;
}