#include <bits/stdc++.h>
using namespace std;
main(){
  //定義と入力受け取り
  int N, M, K, index;
  cin >> N >> M >> K;
  vector<vector<long long>> data(N+1, vector<long long>(K+1, 0));
  
  //初期化処理、一行目(一回目)をMと比較しながら1で埋める
  for(int i=1; i<K+1; i++){
    if(i<=M){data.at(1).at(i) = 1;}
  }
  
  //以下処理、二回目の試行からN回目まで
  for(int i=2; i<N+1; i++){
    
    //Kまでループ
    for(int j=i; j<K+1; j++){
      
      //indexの更新->加算対象の確認(差がMを超えてはならないという制約)
      if(j-M < 1){
        index = 1;
      } else {
        index = j-M;
      }
      
      //一つ前の試行で求めた総和の組み合わせ数から合計して新たな総和の組み合わせ数を更新する
      for(int k=index; k<j; k++){
        data.at(i).at(j) += data.at(i-1).at(k);
      }
      data.at(i).at(j) = data.at(i).at(j)%998244353;
    }
  }
  
  //最終回答算出
  long long count = 0;
  for(int i=1; i<K+1; i++){
    count += data.at(N).at(i);
  }
  cout << count%998244353;
  
}