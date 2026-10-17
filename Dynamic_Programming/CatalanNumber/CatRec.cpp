// Nth Catalan

#include<iostream>
using namespace std;

int catlanRec(int n){
    if(n == 0 || n == 1) return 1;

    int ans = 0;

    for(int i=0; i<n; i++){
        ans += catlanRec(i) * catlanRec(n-i-1);
    }

    return ans;
}

int main(){
    // int n = 4; 

    // cout<< catlanRec(n) <<" "<<endl;

    for(int i=1; i<=6; i++){
        cout<< catlanRec(i) <<" "<<endl;
    }

    return 0;
}