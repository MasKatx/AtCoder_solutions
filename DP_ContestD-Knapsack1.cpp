#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, W;
  long long weight, value;
  long long maxi = 0;
  cin >> N >> W;
  vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));

  for(int i=0; i<N; i++) {
    cin >> weight >> value;
    for(int j=0; j<weight; j++){
      dp.at(i+1).at(j) = dp.at(i).at(j);
    }
    for(int j=0; j<W+1-weight; j++){
      if(dp.at(i).at(j+weight) < dp.at(i).at(j)+value){
        dp.at(i+1).at(j+weight) = dp.at(i).at(j)+value;
        if(maxi < dp.at(i).at(j)+value){
          maxi = dp.at(i).at(j)+value;
        }
      } else {
        dp.at(i+1).at(j+weight) = dp.at(i).at(j+weight);
      }
    }
  }
  cout << maxi << endl;
}