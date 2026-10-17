#include <iostream>
using namespace std;

int fun(int arr[], int n){
    int count = 1;
    int max = arr[0];
    
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            count++;
            max = arr[i];
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int result = fun(arr, n);
    cout<<"Elements are: "<<endl;
    cout<<result<<endl;
    
    return 0;
}