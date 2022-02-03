// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
// 3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.

#include<iostream>
#include<vector>

using namespace std;

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(dr == 0 and dc == 0){
        vector<string> ret;
        ret.push_back("");
        return ret;
    }
    else if(dr < 0 or dc < 0){
        vector<string> ret;
        // ret.push_back("");
        return ret;
    }
    vector<string> solved1 = getMazePaths(sr,sc,dr-1,dc);
    vector<string> solved2 = getMazePaths(sr,sc,dr,dc-1);

    vector<string> ret;
    for(string s:solved1)   ret.push_back("h"+s);
    for(string s:solved2)   ret.push_back("v"+s);

    return ret;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}