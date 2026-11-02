
// Problem Statement :- 

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:
// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.


// Code : 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longComPrefix(vector<string>& strs){

    if(strs.empty()){
        return "";
    }

    string first = strs[0];

    for(int i=0; i<first.size(); i++){

        char ch = first[i];

        for(int j=1; j<strs.size(); j++){
            if(i >= strs[j].size() || strs[j][i] != ch){
                return first.substr(0, i);
            }
        }
    }

    return first;
}

int main(){

    int n;
    cin >> n;

    vector<string> strs(n);

    for(int i=0; i<n; i++){
        cin>>strs[i];
    }

    cout<<longComPrefix(strs)<<endl;

    return 0;

}