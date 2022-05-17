/* Vaneet Saini 
  vsaini@usc.edu
  This program finds the smallest and largest hailstone length
  of numbers between a user-inputted range
  */

#include <iostream>

using namespace std;

int hailstone(int num);

int hailstone(int num){    //find hailstone length function
  int count = 0;

  while (num != 1){
    if (num % 2 == 0){
      num /= 2;
      count++;
    }

    else if (num % 2 == 1){
      num = (num * 3) + 1;
      count++;
    }

    else if (num == 1){
      break;
    }
  }
  return count;
}

int main(){
  int minRange, maxRange;
  int achievedMax, achievedMin;
  long long min = 9999999999999;  
  int max = 0;   //declare max and min to be extreme values 

  cout << "Enter the range that you want to search: ";
  cin >> minRange >> maxRange;
  cout << endl;

  if (minRange > maxRange){    //error handling for invalid input
    cout << "Invalid range" << endl;
  }

  else{
    for (int i = minRange; i <= maxRange; i++){ 
    int hs = hailstone(i); //find length of i'th num
    if (hs > max){
      max = hs;    //if current hs bigger than max, take over
      achievedMax = i;  //just the num that achieved it 
    }
    
    if (hs < min){
      min = hs;   //hs takes over as min if smaller 
      achievedMin = i;
    }
  }
  cout << "Minimum length: " << min << endl;
  cout << "Achieved by: " << achievedMin << endl;
  cout << "Maximum length: " << max << endl;
  cout << "Achieved by: " << achievedMax << endl;   
  }
  
  return 0; 
}
