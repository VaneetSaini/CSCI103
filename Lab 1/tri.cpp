#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int theta;
  cout << "Enter theta [15 to 75]: ";
  cin >> theta;
  cout << endl;
  double radian = (double)theta * (M_PI / 180.0);
  for (int col = 1; col <= 31; col++){
    int xCoordinate = col * tan(radian);
    if (xCoordinate >= 20 && xCoordinate <= 30){
      for (int i = 0; i < 20; i++){
        cout << '*';
      }
    }
    else{
      for (int row = 0; row < xCoordinate; row++){
        cout << '*';
      }
    }
    cout << endl;
  }

  return 0;
}
