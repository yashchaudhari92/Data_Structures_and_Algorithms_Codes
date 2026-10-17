#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1; //last most index of nums1

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        } else {

        }
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    return 0;
}