#include <bits/stdc++.h>
using namespace std;

char fun(char arr[], int n){
    char ans;
    // Declaration
    unordered_map<char, int> mp;
    
    // store
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    
    for(int i=0; i<n; i++){
        if(mp[arr[i]]%2 != 0){
            ans = arr[i];
            break;
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin>>n;
    
    char arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    char result = fun(arr, n);
    cout<<"colour is: "<<endl;
    cout<<result<<endl;
    
    return 0;
}