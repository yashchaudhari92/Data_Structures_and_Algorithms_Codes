// 994. Rotting Oranges — Medium

// You are given an \(m \times n\) grid where each cell can have one of three values:
// - 0 representing an empty cell.
// - 1 representing a fresh orange.
// - 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


// Code :- 


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    // Store all initially rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } 
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) {
        return 0;
    }

    int minutes = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int size = q.size();
        bool rottedThisMinute = false;

        for (int i = 0; i < size; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                    rottedThisMinute = true;
                }
            }
        }

        if (rottedThisMinute) {
            minutes++;
        }
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid elements (0, 1, or 2):\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = orangesRotting(grid);

    cout << "Minimum minutes: " << result << endl;

    return 0;
}