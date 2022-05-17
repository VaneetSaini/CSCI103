#include <iostream>
using namespace std;

int main(){
  cout << "Enter a positive integer: " << endl;
  int input;
  cin >> input;
  int numOfTwo = 0;
  int numOfThree = 0;
  if (input % 2 == 0 || input % 3 == 0){
    while (input % 2 == 0){
      numOfTwo++;
      input /= 2;
    }
    while (input % 3 == 0){
      numOfThree++;
      input /= 3;
    }
  }
  if (input != 1){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
    cout << "Twos=" << numOfTwo << ' ' << "Threes=" << numOfThree << endl;
  }
  return 0;

}
