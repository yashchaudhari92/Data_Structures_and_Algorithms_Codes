// Problem :- Minimum absolute difference Pairs


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> A(n), B(n);

    // Input Array A
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    // Input Array B
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    // Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long absolute = 0;

    // Calculate minimum absolute difference
    for(int i = 0; i < n; i++){
        absolute += abs(A[i] - B[i]);
    }

    cout << absolute << endl;

    return 0;
}
