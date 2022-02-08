// 1. You are given a string str.
// 2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.

#include <iostream>
using namespace std;


void printSS(string ques, string ans){
    if(ques.size() == 0){
        cout<<ans<<'\n';
        return;
    }
    char first = ques[0];
    ques = ques.substr(1);
    printSS(ques,ans+first);
    printSS(ques,ans);
    return;
    
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}