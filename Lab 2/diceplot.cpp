#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int roll();

void printHistogram(int counts[]);

 int main(){
  srand(time(0));
  int n;
  cout << "Enter number of experiments: ";
  cin >> n;
  cout << endl;
  int sums[600];
  int counts[21] = {0};
  for (int i = 0; i < n; i++){
    int sum = 0;
    for (int k = 0; k < 4; k++){
      int rollNum = roll();
      sum += rollNum;
    }
    sums[i] = sum;
  }
  for (int i = 4; i < 25; i++){
    for (int j = 0; j < n; j++){
      if (sums[j] == i){
        counts[i-4] += 1;
      }
    }
  }
  printHistogram(counts);
  
  
  return 0;
} 

int roll(){
  int r = 1 + (rand() % 6);

  return r;
}

void printHistogram(int counts[]){
  for (int i = 0; i < 21; i++){
    cout << i+4 << ':';
    for (int j = 0; j < counts[i]; j++){
      cout << 'X';
    }
    cout << endl;
  }
}
