// Solved using Recursion in O(2^n) complexity

#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int>val, vector<int>wt, int w, int n ){

    if(n == 0 || w == 0){
        return 0;
    }

    int itemVal = val[n-1];
    int itemWt = wt[n-1];

    if(itemWt <= w){
        // Include
        int ans1 = knapSackRec(val, wt, w-itemWt, n-1) + itemVal;

        // Exclude
        int ans2 = knapSackRec(val, wt, w, n-1);

        return max(ans1, ans2);
    } else{
        // Exclude directly
        return knapSackRec(val, wt, w, n-1);
    }

}

int main(){

    vector<int> val = { 15, 14, 10, 45, 30};
    vector<int> wt = { 2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    cout<< knapSackRec(val, wt, w, n)<<endl;

    return 0;
}