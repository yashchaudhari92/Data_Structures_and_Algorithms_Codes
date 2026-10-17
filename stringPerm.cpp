#include<iostream>
#include<string>
using namespace std;

void solve(int a, int b, int c, string &curr, int total){
    if(curr.size() == total){
        cout<< curr << "\n";
        return;
    }

    if(a > 0){                 //run for three levels each and prints two outputs -> abc, acb
        curr.push_back('a');
        solve(a-1, b, c, curr, total);
        curr.pop_back();
    }

    if(b > 0){                 //run for three levels each and prints two outputs -> bac, bca
        curr.push_back('b');
        solve(a, b-1, c, curr, total);
        curr.pop_back();
    }

    if(c > 0){                 //run for three levels each and prints two outputs -> cab, cba
        curr.push_back('c');
        solve(a, b, c-1, curr, total);
        curr.pop_back();
    }

}

int main(){
    int n1, n2, n3;

    cout<<"Enter the number of times 'a' appears: "<<endl;
    cin>>n1;

    cout<<"Enter the number of times 'b' appears: "<<endl;
    cin>>n2;

    cout<<"Enter the number of times 'c' appears: "<<endl;
    cin>>n3;

    string curr = "";

    solve(n1, n2, n3, curr, n1+n2+n3);

}