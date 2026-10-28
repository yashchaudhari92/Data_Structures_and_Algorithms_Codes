// Problem Statement :

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.


// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1, 2, 3], the following are all the permutations of arr: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].

// The next permutation of an array of integers is the next lexicographically greater permutation of its integers. More formally, 
// if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation 
// of that array is the permutation that follows it in the sorted container. If such an arrangement is not possible, the array must 
// be rearranged in the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographically larger rearrangement.

// Example 1:
// Input: nums = [1, 2, 3]
// Output: [1, 3, 2]

// Example 2:
// Input: nums = [3, 2, 1]
// Output: [1, 2, 3]

// Example 3:
// Input: nums = [1, 1, 5]
// Output: [1, 5, 1]



// Code :- Using Recursion, set, and Backtracking ( Bruete force approach)

// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// using namespace std;

// // Find all unique permutations
// void helper(vector<int>& nums, int index, int n, set<vector<int>>& uniqPerms){

//     if(index == n){
//         uniqPerms.insert(nums);
//         return;
//     }

//     for(int i=index; i<n; i++){
//         // Swap
//         swap(nums[i], nums[index]);

//         // Recursive call
//         helper(nums, index+1, n, uniqPerms);

//         // Backtrack
//         swap(nums[i], nums[index]);     // Backtracking
//     }

// }

// void nextPermutation(vector<int>& nums){

//     int n = nums.size();

//     set<vector<int>> uniqPerms;

//     // Generate all unique permutations
//     helper(nums, 0, n, uniqPerms);

//     // Convert sorted set into vector
//     vector<vector<int>> ans(uniqPerms.begin(), uniqPerms.end());

//     int m = ans.size();

//     // Find next permutation
//     for(int i=0; i<m; i++){
//         if(ans[i] == nums){
//             nums = ans[(i+1) % m];
//             break;
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> nums(n);

//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     nextPermutation(nums);

//     for (int num : nums) {
//         cout << num << " ";
//     }

//     cout << endl;

//     return 0;
// }



// Code :- Using Optimal Approach

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
        void swap(vector<int>& nums, int i, int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        void reverse(vector<int>& nums, int start, int end){
            while(start < end){
                swap(nums, start, end);
                start++;
                end--;
            }
        }
    
    public:
        void nextPermutation(vector<int>& nums){

            int n = nums.size();
            int index = -1;

            // Find the Pivot
            for(int i = n-2; i >= 0; i--){
                if(nums[i] < nums[i+1]){
                    index = i;
                    break;
                }
            }

            // Find next smaller element from suffix and it should be greater than pivot
            for(int i = n-1; i>=index; i--){
                if(nums[i] > nums[index]){
                    swap(nums, i, index);
                    break;
                }
            }

            // Reverse the Suffixes
            reverse(nums, index+1, n-1);

        }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    sol.nextPermutation(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}