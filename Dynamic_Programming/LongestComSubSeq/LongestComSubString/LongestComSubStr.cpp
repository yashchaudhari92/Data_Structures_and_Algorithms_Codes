#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LcsTabu(string str1, string str2){

    int n = str1.size();
    int m = str2.size();

    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){

            if(str1[i-1] == str2[j-1]){
                // Yes -  If Last Both char are equal then add 1 and reduce the length of both strings
                dp[i][j] = dp[i-1][j-1] + 1;

            } else {
                // No condition
                dp[i][j] = 0;
            }

            // Compare to track the curr length, because here we've changed the meaning of dp[i][j].
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;

}

int main(){
    string str1 = "abcdge";
    string str2 = "abedg";


    cout<<LcsTabu(str1, str2)<<endl;

    return 0;
}