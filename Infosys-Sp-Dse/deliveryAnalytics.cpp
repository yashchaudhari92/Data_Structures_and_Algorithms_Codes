#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

long long countRevenuePeriods(vector<int>&revenues, long long k){

    unordered_map<long long , long long> prefixCount;

    prefixCount[0] = 1;

    long long prefixSum = 0;
    long long totalPeriods = 0;

    for(int value : revenues){
        prefixSum +=  value;

        // Carefully understand this concept

        long long required = prefixSum - k;

        if(prefixCount.find(required) != prefixCount.end()){
            totalPeriods += prefixCount[required];
        }

        prefixCount[prefixSum]++;
    }

    return totalPeriods;

}

int main(){
    int n, k;

    cin >> n >> k;

    vector<int> revenues(n);

    for(int i=0; i<n; i++){
        cin>>revenues[i];
    }

    cout<<countRevenuePeriods(revenues, k)<<endl;

    return 0;
}