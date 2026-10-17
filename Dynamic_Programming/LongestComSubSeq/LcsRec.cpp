#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LcsRec(string str1, string str2){

    if(str1.size() == 0 || str2.size() == 0){
        return 0;
    }
    
    int n = str1.size();
    int m = str2.size();


    if(str1[n-1] == str2[m-1]){

        // If Last Both char are equal then add 1 and reduce the length of both strings
        return 1 + LcsRec(str1.substr(0, n-1), str2.substr(0, m-1));
    } else{

        // Reduce the length of both strings one by one, because we dont know by reducing which str we'll get ans.
        int ans1= LcsRec(str1.substr(0, n-1), str2);
        int ans2 = LcsRec(str1, str2.substr(0, m-1));

        // Take their maximum
        return max(ans1, ans2);
    }
}

int main(){
    string str1 = "abcdge";
    string str2 = "abedg";

    cout<<LcsRec(str1, str2)<<endl;

    return 0;
}