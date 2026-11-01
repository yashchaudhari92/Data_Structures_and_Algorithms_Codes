// Problem Statement :

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: s = " hello world "
// Output: "world hello"


// Code :- Using Better Approach

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string reverse(string s){
    vector<string> words;
    string word = "";

    // Step 1: Traverse and extract words
    for(char c : s){
        if(c != ' '){
            word += c;
        } else if(!word.empty()){
            words.push_back(word);
            word = "";
        }
    }

    // Add the last word if any
    if(!word.empty()){
        words.push_back(word);
    }

    // Step 2: Reverse the vector of words
    reverse(words.begin(), words.end());

    // Step 3: Join words with a single space
    string result = "";
    for(int i=0; i<words.size(); ++i){
        result += words[i];
        if(i < words.size()-1)
        result += " ";
    }

    return result;
}


int main(){
    string s;
    getline(cin, s);

    string result = reverse(s);

    cout<<result<<endl;

    return 0;

}
