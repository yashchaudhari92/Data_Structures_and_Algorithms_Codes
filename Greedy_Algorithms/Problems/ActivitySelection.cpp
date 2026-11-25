
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxActivities(vector<int>& start, vector<int>& end){

    int n = start.size();

    // Store {End Time, Start Time, Original Index}
    vector<pair<pair<int,int>, int>> activities;

    // Create activity pairs
    for(int i = 0; i < n; i++){
        activities.push_back({{end[i], start[i]}, i});
    }

    // Sort activities based on End Time
    sort(activities.begin(), activities.end());

    int count = 0;
    int currEndTime = -1;

    // Select activities using Greedy
    for(int i = 0; i < n; i++){

        int endTime = activities[i].first.first;
        int startTime = activities[i].first.second;
        int originalIndex = activities[i].second;

        // Non-overlapping condition
        if(startTime >= currEndTime){

            cout << "Selecting A" << originalIndex << endl;

            count++;

            // Update current end time
            currEndTime = endTime;
        }
    }

    return count;
}

int main(){

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum Activities: "
         << maxActivities(start, end) << endl;

    return 0;
}
