#include "bigint.h"
#include <string>
#include <vector> 
#include <sstream>
#include <iostream>
using namespace std;

BigInt::BigInt(string s){  //constructor 
  for (int i = s.size()-1; i >=0; i--){
    value.push_back((int)s[i] - 48); //convert char to int 
  }
};

string BigInt::to_string(){  //to_string() function
  string x = "";
  for (int i = value.size() - 1; i >= 0; i--){
    x += (char)(value[i] +48);
  }
  return x;
};

void BigInt::add(BigInt a){   //add() function
  int difference = 0;
  if (value.size() > a.value.size())
    difference = value.size() - a.value.size();
  else if (value.size() < a.value.size())
    difference = a.value.size() - value.size();
  for (int i = 0; i < difference; i++){
    if (value.size() < a.value.size()){
      value.push_back(0);

    }
    else if (value.size() > a.value.size()){
      a.value.push_back(0);
    }
  }
  int carried = 0; 
  for (unsigned int i = 0; i < value.size(); i++){
    int temp = value[i] + a.value[i] + carried;
    carried = temp/10;
    value[i] = temp % 10;
  }
  if (carried > 0){
    value.push_back(carried);
  }
};
