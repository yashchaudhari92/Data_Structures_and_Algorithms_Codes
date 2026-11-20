// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0
// Explanation:
// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1

// We didn't need stack here to solve this problem, we can solve this problem using frequency counting.

// Step 1: Create frequency array
// Step 2: Count character frequencies
// Step 3: Find first non-repeating character
// Step 4: No unique character found

// Code:

#include<iostream>
#include<string>
using namespace std;

class Solution{
    public: 

        int firstUniqChar(string s){

            int freq[26] = {0};

            for(int i=0; i<s.length(); i++){
                freq[s[i] - 'a']++;
            }

            // find first non-repeating character
            for(int i=0; i<s.length(); i++){
                if(freq[s[i] - 'a'] == 1){
                    return i;
                }
            }

            return -1;
        }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter a string: ";
    cin >> s;

    int ans = obj.firstUniqChar(s);

    cout << "First Unique Character Index: " << ans << endl;

    return 0;
}