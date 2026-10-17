// Problem :- Minimum absolute difference Pairs

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> A = { 4, 1, 8, 7};
    vector<int> B = { 2, 3, 6, 5};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absolute = 0;
    for(int i = 0; i < A.size(); i++){
        absolute += abs(A[i] - B[i]);
    }

    cout<<"Minimum Absolute Difference: "<<absolute<<endl;
    return 0;
}