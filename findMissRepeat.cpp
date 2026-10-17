#include<iostream>
#include<vector>
using namespace std;

vector<int> findMissingAndReapetingNum(vector<vector<int>>& grid){
    int n = grid.size();
    long N = n * n;

    vector<bool> seen(N + 1, false);
    int repeatedNum = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num = grid[i][j];
            if(seen[num]){
                repeatedNum = num;
            }
            seen[num] = true;
        }
    }

    int missingNum = -1;
    for(int i = 1; i <= N; i++){
        if(!seen[i]){
            missingNum = i;
            break;
        }
    }

    return { repeatedNum, missingNum};
}

int main(){
    vector<vector<int>> grid = {
    {1, 3},
    {2, 2}
};

    vector<int> ans = findMissingAndReapetingNum(grid);
    cout << "Repeated: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}