#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
  if(idx == arr.size()){
    vector<int> ret;
    return ret;
  }  
  // vector<int> ret;
  
  vector<int> ret = allIndex(arr,idx+1,data,count);

  if(arr[idx] == data)  ret.push_back(idx);
  return ret;
  
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  reverse(ans.begin(),ans.end());
  for (int ele : ans) cout << ele << endl;

  return 0;
}