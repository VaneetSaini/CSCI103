#include <iostream>
#include "bigint.h"
using namespace std;

int main(int argc, char* argv[]){
  BigInt a("4321");
  vector<int> b = a.value;
  return 0;
}
