#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n <= 0){
        return 0;
    }

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> result(2*n);

    for(int i=0; i<2*n; i++){
        result[i] = arr[i%n];
    }

    // Playlist Printing
    for(int i=0; i<2*n; i++){
        cout<<result[i]<<",";
    }

    return 0;
}