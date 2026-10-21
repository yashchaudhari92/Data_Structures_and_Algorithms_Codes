// # Problem Statement: Seasons

// Rhea Pandey’s teacher has asked her to prepare well for the lesson on seasons. When her teacher tells a month, she needs to say the season corresponding to that month.

// Write a program to solve the above task.

// - **Spring:** March to May
// - **Summer:** June to August
// - **Autumn:** September to November
// - **Winter:** December to February

// The month should be in the range 1 to 12. If not, the output should be **"Invalid month"**.

// ### Sample Input 1
// ```text
// Enter the month: 11
// ```

// ### Sample Output 1
// ```text
// Season: Autumn
// ```

// ### Sample Input 2
// ```text
// Enter the month: 13
// ```

// ### Sample Output 2
// ```text
// Invalid month
// ```



// Code :- 

#include<iostream>
using namespace std;

void seasonProblem(int month){

    if(month < 1 || month > 12){
        cout<<"Invalid Month.."<<endl;
    } else if(month >= 3 && month <= 5){
        cout<<"Season: Spring"<<endl;
    } else if(month >= 6 && month <= 8){
        cout<<"Season: Summer"<<endl;
    } else if(month >= 9 && month <= 11){
        cout<<"Season: Autumn"<<endl;
    } else{
        cout<<"Season: Winter";
    }

}

int main(){
    int month;
    cout<<"Enter the Month: "<<endl;
    cin>>month;

    seasonProblem(month);

    return 0;
}