// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for 
// every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could 
// search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// Code :


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{

    public: 

        vector<int> nextGreaterElements(vector<int>& nums){
            int n = nums.size();

            vector<int> ans(n, -1);
            stack<int> s;

            for(int i=0; i<2*n -1; i++){
                int curr = nums[i%n];

                while(!s.empty() && curr > nums[s.top()]){
                    int index = s.top();
                    s.pop();

                    ans[index] = curr;
                }

                if(i < n){
                    s.push(i);
                }
            }

            return ans;
        
        }
};

int main(){
    Solution obj;
    int n;

    cout<<"Enter a size of nums array: "<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter Elements of nums array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> result = obj. nextGreaterElements(nums);

    cout<<"The next greater elements are: "<<endl;
    for(int x : result){
        cout<< x << " ";
    }

    return 0;

}