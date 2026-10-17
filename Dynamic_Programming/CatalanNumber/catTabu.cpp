// Nth Catalan

#include<iostream>
#include<vector>
using namespace std;

int catlanRec(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main(){
    // int n = 4; 

    // cout<< catlanRec(n) <<" "<<endl;

    int n = 6;

    for(int i=1; i<=n; i++){
        cout<< catlanRec(i) <<" "<<endl;
    }

    return 0;
}