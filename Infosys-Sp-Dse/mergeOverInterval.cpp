// Problem Statement :

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the 
// non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
// Output: [[1, 6], [8, 10], [15, 18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1, 5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.



// Code :- using optimal approach 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<long long>> mergeIntervals(vector<vector<long long>>& intervals){
    
    // Sort the Intervals on start time
    sort(intervals.begin(), intervals.end());

    vector<vector<long long>> merged;

    for(const auto& interval : intervals){
        if(merged.empty() || interval[0] > merged.back()[1]){
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}


int main(){

    int n;
    cin>>n;

    vector<vector<long long>> intervals(n, vector<long long> (2));

    for(int i=0; i<n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<long long>> result = mergeIntervals(intervals);

    cout<<"--------OUTPUT--------"<<endl;

    cout<<result.size()<<endl;

    for(const auto& interval : result){
        cout<<interval[0] << " "<< interval[1]<<endl;
    }

    return 0;

}