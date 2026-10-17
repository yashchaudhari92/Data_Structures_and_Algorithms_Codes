#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;         //Sort in Descending based on ratios.
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w){
    
    int n = val.size();
    vector<pair<double, int>> ratios(n, make_pair(0.0, 0));  // pair of ratios and index to track original index after sorting pair(ratio, idx)

    // Calcute ratios
    for(int i=0; i<n; i++){
        double r = val[i]/(double)wt[i];
        ratios[i] = make_pair(r, i);
    }

    // Sort the ratios
    sort(ratios.begin(), ratios.end(), compare);

    // main work to Fill the snapsack
    int ans = 0;
    for(int i=0; i<n; i++){
        int idx = ratios[i].second;
        if(wt[idx] <= w){
            ans += val[idx];
            w -= wt[idx];
        } else {
            ans += ratios[i].first * w;
            w = 0; 
            break;
        }
    }

    cout<<"Max value: "<<ans<<endl;
    return ans;
}

int main(){
    vector<int> val = { 60, 100, 120};
    vector<int> wt = { 10, 20, 30};
    int w = 50;

    fractionalKnapsack(val, wt, w);

    return 0;
}