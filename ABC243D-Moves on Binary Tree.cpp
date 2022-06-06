#include <bits/stdc++.h>
using namespace std;
int main(void){
  int num;
  long long value;
  string instructions;
  cin >> num >> value >> instructions;
  vector<char> instruction(0);
  
  for(int i=0; i<num; i++){
    if(instruction.size() > 0){
      if(instruction.at(instruction.size()-1) != 'U' && instructions.at(i) == 'U'){
        instruction.pop_back();
      } else {
        instruction.push_back(instructions.at(i));
      }
    } else {
        instruction.push_back(instructions.at(i));
    }
  }

  for(auto &item:instruction){
    if(item == 'L'){
      value *= 2;
    } else if(item == 'R'){
      value *= 2;
      value ++;
    } else {
      value /=2;
    }
  }
  cout << value << endl;
}