// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
// If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


// solution using STL Stack and unordered_map:

// Step 1: Find next greater element for nums2
//     Find next greater elements

// Step 2: Remaining elements have no greater element

// Step 3: Build answer for nums1


// Code: 


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution{
    public:

        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

            stack<int> s;
            unordered_map<int, int> mp;

            for(int i=0; i<nums2.size(); i++){

                int curr =  nums2[i];

                while(!s.empty() && curr > s.top()){
                    mp[s.top()] = curr;
                    s.pop();
                }

                s.push(curr);
            }

            while(!s.empty()){
                mp[s.top()] = -1;
                s.pop();
            }

            vector<int> ans;

            for(int i=0; i<nums1.size(); i++){
                ans.push_back(mp[nums1[i]]);
            }

            return ans;
        }
};

int main() {

    Solution obj;

    int n, m;

    cout << "Enter size of nums1: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter nums1 elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of nums2: ";
    cin >> m;

    vector<int> nums2(m);

    cout << "Enter nums2 elements: ";
    for(int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}