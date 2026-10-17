#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LcsMemo(string str1, string str2, vector<vector<int>> dp){

    if(str1.size() == 0 || str2.size() == 0){
        return 0;
    }
    
    int n = str1.size();
    int m = str2.size();

    if(dp[n][m] != -1){
        return dp[n][m];
    }


    if(str1[n-1] == str2[m-1]){

        // If Last Both char are equal then add 1 and reduce the length of both strings
        dp[n][m] =  1 + LcsMemo(str1.substr(0, n-1), str2.substr(0, m-1), dp);
    } else{

        // Reduce the length of both strings one by one, because we dont know by reducing which str we'll get ans.
        int ans1= LcsMemo(str1.substr(0, n-1), str2, dp);
        int ans2 = LcsMemo(str1, str2.substr(0, m-1), dp);

        // Take their maximum
        dp[n][m] = max(ans1, ans2);
    }

    return dp[n][m];
}

int main(){
    string str1 = "abcdge";
    string str2 = "abedg";

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout<<LcsMemo(str1, str2, dp)<<endl;

    return 0;
}