// Auction Revenue Calculation

// There are N items at auction and M bidders. Each bidder j has a budget b[j] and submits one bid per item; bid[j][i] is bidder j's bid on item i.

// An item is awarded to the highest bidder who can afford it (bid[j][i] <= b[j]). A bidder cannot bid more than their budget. Ties are broken by lower bidder index.

// Each bidder wins at most one item: once a bidder wins an item, their budget is exhausted and they cannot win another.

// Items are auctioned in order from 1 to N. Find the total revenue (sum of winning bids across all items).
// Input format
// - The first line contains integer N, the number of items.
// - The second line contains integer M, the number of bidders.
// - The next M lines each contain one integer b[j], the budget of a bidder.
// - The next M lines each contain N space-separated integers representing that bidder's bids on the items.
// Sample input
// 3
// 3
// 10
// 20
// 30
// 5 5 5
// 10 15 10
// 5 20 25


// Expected output
// 35


// Code :- 

// Steps :- 
// 1. Take the Input in given input format
// 2. Input bids of every bidder on every item
// 3. create a bool array to see if any bidder already won an item or exhausted their budget.
// 4. Auction items one by one





#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    // Budget of Bidder
    vector<int> budget(M);

    for(int j=0; j<M; j++){
        cin >> budget[j];
    }

    // Input bids of every bidder on every item
    vector<vector<int>> bid(M, vector<int> (N));

    for(int j=0; j<M; j++){
        for(int i=0; i<N; i++){
            cin >> bid[j][i];
        }
    }

    vector<bool> won(M, false);
    long long totalRevenue = 0;

    // Auction items one by one
    for(int i=0; i<N; i++){
        int winner = -1;
        int highestBid = -1;

        for(int j=0; j<M; j++){
            if(!won[j] && bid[j][i] <= budget[j]){
                if(bid[j][i] > highestBid){
                    highestBid = bid[j][i];
                    winner = j;
                }
            }
        }

        if(winner != -1){
            totalRevenue += highestBid;
            won[winner] = true;
        }
    }

    cout << totalRevenue << '\n';

    return 0;
}