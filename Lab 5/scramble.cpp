
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;


// Scramble the letters of this string randomly
void permute(char items[], int len);

/* Delete the array below and replace by reading in words from a file 
   in main() */
//array deleted

int main(int argc, char* argv[]) {
  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;

  /* Add code to declare the wordBank array, read in each word
     and store it */
  ifstream ifile (argv[1]);
  if (argc < 2){
    cout << "Not enough command line arguments." << '\n';
    return 0;
  }
  if (argc > 2){
    cout << "Too many command line arguements." << '\n';
    return 0;
  }
  if (ifile.fail()){
    cout << "Error opening file." << '\n';
    return 0;
  }
  int numWords;
  if (!(ifile >> numWords)){
    cout << "Could not read integer." << '\n';
    ifile.close();
    return 0;
  }

  char** wordBank = new char* [numWords];
  char buffer[41];

  int i = 0;
  for (i = 0; i < numWords; i++){
    ifile >> buffer;
    wordBank[i] = new char[strlen(buffer) + 1];
    strcpy(wordBank[i], buffer);
  }

  ifile.close();

  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (!wordGuessed && numTurns > 0) {
    cout << "Scrambled word: " << word << endl;
    cout << "What do you guess the original word is? ";
    cin >> guess;
    /* Complete the next line of code */
      
    wordGuessed = (strcmp(guess, wordBank[target]) == 0);// ADD code to check if the guess is equal to the chosen word.
                  // wordGuessed should be true if they are equal, and false otherwise
        
    numTurns--;   // Every guess counts as a turn
  }
  if (wordGuessed) {
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  /* Free up any necessary memory */
  for (int i = 0; i < numWords; i++){
    delete [] wordBank[i];
  }
  delete [] wordBank;
  delete [] word;

  return 0;
}

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}

