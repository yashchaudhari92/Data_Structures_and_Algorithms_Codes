// Problem Statement :

// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately but instead be stored in the input character array chars. 
// Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.


// Example 1:
// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

// Example 2:
// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.

// Code :- Using Best Optimal Approach


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int compress(vector<char>& chars){

    chars.push_back('~');
    int n = chars.size();

    int i = 0;
    int j = 1;
    int count = 1;

    while(j < n){

        if(chars[j] == chars[j-1]){
            count++;
        }
        else{
            chars[i] = chars[j-1];
            i++;

            if(count >= 2){
                string len = to_string(count);

                for(auto x : len){
                    chars[i] = x;
                    i++;
                }
            }

            count = 1;
        }

        j++;
    }

    return i;
}

int main(){

    int n;
    cin >> n;

    vector<char> chars(n);

    for(int i = 0; i < n; i++){
        cin >> chars[i];
    }

    int result = compress(chars);

    cout << result << endl;

    for(int i = 0; i < result; i++){
        cout << chars[i] << " ";
    }

    return 0;
}
