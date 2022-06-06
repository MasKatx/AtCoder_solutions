#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  cin >> N;
  //data[n] = [x, y, LR]
  vector<vector<int>> data(N, vector<int>(3));
  int input;
  for(int i=0; i<N; i++){
    cin >> input;
    data.at(i).at(0) = input;
    cin >> input;
    data.at(i).at(1) = input;
  }
  string foo;
  cin >> foo;
  for(int i=0; i<N; i++){
    if(foo.at(i) == 'R'){
      data.at(i).at(2) = 0;	//Rで0
    } else {
      data.at(i).at(2) = 1;	//Lで1
    }
  }
  bool flg = true;
  
  //collision[y] = [左端x(R), 右端x(L)]
  map<int, vector<int>> collision;
  //beforemap[y] = [x, LR]
  map<int, vector<int>> beforeMap;
  
  for(int i=0; i<N; i++){
    //data.at(i) = [x, y, LR]
	if (beforeMap[data.at(i).at(1)].size() < 2){
      //入力待ちすら、なにもない状態
      beforeMap[data.at(i).at(1)].push_back(data.at(i).at(0));
      beforeMap[data.at(i).at(1)].push_back(data.at(i).at(2));
    } else if (collision[data.at(i).at(1)].size() == 0){
      //入力待ちが1以上ある状態かつ本マップに未入力の状態
      if(beforeMap[data.at(i).at(1)].at(1) == data.at(i).at(2)){
        //向かう方向が同じ場合
        if(data.at(i).at(2) == 0){
          //R
          if(data.at(i).at(0) < beforeMap[data.at(i).at(1)].at(0)){
          	beforeMap[data.at(i).at(1)].at(0) = data.at(i).at(0);
          }
        } else {
          //L
          if(data.at(i).at(0) > beforeMap[data.at(i).at(1)].at(0)){
          	beforeMap[data.at(i).at(1)].at(0) = data.at(i).at(0);
          }
        }
      } else {
        //向かう方向が逆の場合、collisionに本挿入
        if(data.at(i).at(2) == 0){
          collision[data.at(i).at(1)].push_back(data.at(i).at(0));
          collision[data.at(i).at(1)].push_back(beforeMap[data.at(i).at(1)].at(0));
        } else {
          collision[data.at(i).at(1)].push_back(beforeMap[data.at(i).at(1)].at(0));
          collision[data.at(i).at(1)].push_back(data.at(i).at(0));
        }
        if(collision[data.at(i).at(1)].at(0) < collision[data.at(i).at(1)].at(1)){
          flg = false;
          break;
      	}
      }      
    } else {
      //既に本マップが入力済みの状態で、それよりも限界値が検証された場合に入れ替え
      if(data.at(i).at(2) == 0){
        //R
        if(data.at(i).at(0) < collision[data.at(i).at(1)].at(0)){
      	  collision[data.at(i).at(1)].at(0) = data.at(i).at(0);
        }
      } else {
        //L
        if(data.at(i).at(0) > collision[data.at(i).at(1)].at(1)){
           collision[data.at(i).at(1)].at(1) = data.at(i).at(0);
        }
      }
      if(collision[data.at(i).at(1)].at(0) < collision[data.at(i).at(1)].at(1)){
        flg = false;
        break;
      }
    }
    //endif
  }
  //endfor 
  
  if(flg){
	cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
    
//  for (auto i = collision.begin(); i != collision.end(); ++i) {
//    if(i->second.size() == 2)cout << i->first << " => " << i->second.at(0) << ", " << i->second.at(1) << endl;
//  }
  
}