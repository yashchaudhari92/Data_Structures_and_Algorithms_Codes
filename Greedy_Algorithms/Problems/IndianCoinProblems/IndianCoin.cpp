#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMinChange(vector<int> coins, int v){
    int n = coins.size()-1;

    int ans = 0;
    for(int i = n; i>=0 && v > 0; i--){
        if(v >= coins[i]){

            // These two formulas are important always remember 
            ans += v/coins[i];    //---> return the Quetient which is the min number of coin that we can take
            v = v%coins[i];       //---> return the remainder, how much value is left.
        }
    }

    cout<<"minimum coins we can give: "<<ans<<endl;

    return ans;
}

int main(){

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int v = 1099;

    getMinChange(coins, v);
    return 0;
}