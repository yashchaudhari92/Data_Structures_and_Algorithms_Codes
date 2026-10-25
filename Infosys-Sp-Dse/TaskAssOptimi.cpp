// Task Assignment Optimization

// You are given N tasks and M workers.

// Each task i (from 1 to N) is defined by:
// - d[i]: the minimum skill level required to complete the task.
// - w[i]: the profit earned upon completing the task.
// Each worker j (from 1 to M) possesses a skill level s[j].

// A worker can complete a task only if their skill level is greater than or equal to the task's required skill level. Each worker can be assigned at most one task, and each task can be assigned to at most one worker.

// Find the maximum total profit achievable by optimally assigning tasks to workers.
// Input format
// 1. The first line contains integer N, the number of tasks.
// 2. The second line contains integer M, the number of workers.
// 3. The next N lines each contain two space-separated integers: d[i] and w[i].
// 4. The next M lines each contain one integer: s[j], the skill level of worker j.

// Sample Input :- 
// 3
// 1
// 10 100
// 5 50
// 12 120
// 10


// Code :- Using Greedy Approach

// Steps :- 
// 1. Take the Input in given input format
// 2. Sort them in increasing order
// 3. Use priority Queue to store the task that worker can do. (highest profit task comes first).\
// 4. use for loop, add every task the particular worker can perform.
// 5. Assign the most profitable available task.
// 6. print total profit.

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> tasks(N);

    // Each task: {required skill, profit}
    for(int i=0; i<N; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }

    vector<int> workers(M);

    for(int i=0; i<M; i++){
        cin >> workers[i];
    }

    // Sort tasks by required skill
    sort(tasks.begin(), tasks.end());

    // Process workers from lowest skill to highest
    sort(workers.begin(), workers.end());

    // Max-heap: highest profit task comes first
    priority_queue<int> profits;

    int j = 0;      // j representing the first tasks in the sorted task list.
    long long totalProfit = 0;

    for(int i=0; i<M; i++){

        // Add every task this worker can perform
        while(j < N && tasks[j].first <= workers[i]){
            profits.push(tasks[j].second);
            j++;
        }
        
        // Assign the most profitable available task
        if(!profits.empty()){
            totalProfit += profits.top();
            profits.pop();
        }
    }

    cout << totalProfit << endl;

    return 0;

}