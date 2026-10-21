// # Count Distinct Substrings with Exactly K Unique Characters

// ## Problem

// Given a string `s` and an integer `k`, count the number of distinct substrings that contain exactly `k` unique characters.

// ## Example

// **Input**
// ```text
// abcbaa
// 3
// ```

// **Output**
// ```text
// 3
// ```


// Code :- 

#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int countOfdistinctSubstr(string s, int k){

    unordered_set<string> distinctSubstrs;
    int distinctSubstrsCount = 0;

    for(int left=0; left<s.size(); left++){
        unordered_map<char, int> frequency;
        int uniqueCount = 0;

        for(int right = left; right<s.size(); right++){
            char ch = s[right];

            if(frequency[ch] == 0){
                uniqueCount++;
            }

            frequency[ch]++;

            // If Too many unique characters:
            // extending the window cannot fix it, so
            if(uniqueCount > k){
                break;
            }

            if(uniqueCount == k){
                distinctSubstrs.insert(
                    s.substr(left, right - left + 1 )
                );

                distinctSubstrsCount++;
            }
        }

    }

    return distinctSubstrsCount;
}

int main(){

    string s;
    int k;

    cin >> s >> k;

    cout<<countOfdistinctSubstr(s, k)<<endl;

    return 0;

}

