// User Session - Longest unique action sequence Problem

// Sliding Window Concept

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int longestUniqueSubstr(string s){

    vector<int> lastSeen(128,-1);

    int left = 0;
    int currentLength = 0;
    int maxLength = 0;

    for(int right = 0; right < s.size(); right++){
        char ch = s[right];

        if(lastSeen[ch] >= left){
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right;

        // Update the longest valid window
        currentLength = right - left + 1;
        maxLength = max(currentLength, maxLength);
    }

    return maxLength;
}

int main(){
    string s;
    cin>>s;

    cout<<longestUniqueSubstr(s)<<endl;

    return 0;

}
