#include <bits/stdc++.h>
using namespace std;
main(){
  int n, k;
  bool flg = true;
  cin >> n >> k;
  vector<int> sequence(n);
  vector<vector<int>> classified(k, vector<int>(0));
  for(int i=0; i<n; i++){
    cin >> sequence.at(i);
    classified.at(i%k).push_back(sequence.at(i));
  }
  
  sort(sequence.begin(), sequence.end());
  for(int i=0; i<k; i++){
    sort(classified.at(i).begin(), classified.at(i).end());
  }
  
  for(int i=0; i<n; i++){
    if(sequence.at(i) != classified.at(i%k).at(i/k)){
      flg = false;
      break;
    }
  }
  
  if(flg){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}