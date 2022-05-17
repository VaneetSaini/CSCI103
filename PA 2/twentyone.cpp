//Vaneet Saini
//vsaini@usc.edu
/* This program simulates a game of BlackJack by using seeds to 
generate psuedo random cards for the dealer and player. There are functions
to shuffle the deck of cards, get the card value, print cards, print hands,
and get the score of a hand. */ 
/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA 2
/******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'}; //used for printCard
const char* type[13] = 
  {"2","3","4","5","6","7",         //used for printCard
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11}; //used for cardValue

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
  for (int i = 0; i < 52; i++){  //intialize deck to have val 0-51
    cards[i] = i;
  }
  for (int i = NUM_CARDS-1; i >= 1; i--){ //Fisher-Yates
    int j = rand() % (i+1);  //random number from 0 to i inclusive
    int temp = cards[i];
    cards[i] = cards[j];       //swap idiom 
    cards[j] = temp;
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */

void printCard(int id)
{
  /******** You complete ****************/
  cout << type[id % 13] << '-' << suit[id / 13];
  //used global arrays to print type-suit
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
  return value[id % 13];   //matches up with value global array

}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
  for (int i = 0; i < numCards; i++){  //iterate through deck
    printCard(hand[i]);  //prints each card in hand
    cout << ' ';
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
  int sum = 0;
  for (int i = 0; i < numCards; i++){
    int val = cardValue(hand[i]);//card value of card i in hand
    sum += val;  
  }
  for (int i = 0; i < numCards; i++){
    if (cardValue(hand[i]) == 11 && sum > 21){ 
      sum -= 10; //reiterates and checks if aces and over 21
    }
  }

  return sum;
}
/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
  bool condition = 1;  //true condition
  while(condition){
    shuffle(cards); //shuffles the cards before they're dealt
    phand[0] = cards[0];
    dhand[0] = cards[1];   //dealed to player and dealer
    phand[1] = cards[2];   //in an alternating fashion
    dhand[1] = cards[3];

    int playersAmt = 2;  //amt of cards
    int dealersAmt = 2;
    cout << "Dealer: ? ";
    printCard(dhand[1]);   //prints second card of dealer
    cout << endl;
    cout << "Player: ";
    printHand(phand, playersAmt); //prints first 2 cards
    
    while (getBestScore(phand, playersAmt) < 21){
      char input;  //while player doesnt have 21
      cout << "Type 'h' to hit and 's' to stay: " << endl;
      cin >> input; 
      if (input == 'h'){
        phand[playersAmt] = cards[2+playersAmt]; //draws another card
        playersAmt++;  //updates card amount
        cout << "Player: ";
        printHand(phand, playersAmt); //prints current hand
      }
      else if (input == 's'){
        break; //exists loop if they dont hit
      }
      else{
        return 0; //quits program if something else typed
      }
    }

    if (getBestScore(phand, playersAmt) > 21){ //if bust
      cout << "Player busts" << endl;
      cout << "Lose ";
      cout << getBestScore(phand, playersAmt) << ' ';
      cout << getBestScore(dhand, dealersAmt);
      cout << "\n"; 
    }
    else {        //the game continues..
      while (getBestScore(dhand, dealersAmt) <= 16){
        dhand[dealersAmt] = cards[dealersAmt+playersAmt];
        dealersAmt++;  //dealer has to hit if value under 17
      }
      cout << "Dealer: ";
      printHand(dhand, dealersAmt);

      if (getBestScore(dhand, dealersAmt) > 21){
        cout << "Dealer busts" << endl;
        cout << "Win ";
        cout << getBestScore(phand, playersAmt);
        cout << " ";
        cout << getBestScore(dhand, dealersAmt);
      }
      else if (getBestScore(dhand, dealersAmt) < 21){
        if (getBestScore(phand, playersAmt) < getBestScore(dhand, dealersAmt)){
          cout << "Lose ";
          cout << getBestScore(phand, playersAmt);
          cout << " ";
          cout << getBestScore(dhand, dealersAmt);
        }
        else if (getBestScore(phand, playersAmt) > getBestScore(dhand, dealersAmt)){
          cout << "Win ";
          cout << getBestScore(phand, playersAmt);
          cout << " ";
          cout << getBestScore(dhand, dealersAmt);
        }
        else if (getBestScore(phand, playersAmt) == getBestScore(dhand, dealersAmt)){
          cout << "Tie ";
          cout << getBestScore(phand, playersAmt);
          cout << " ";
          cout << getBestScore(dhand, dealersAmt);
        }
      }
    }
    cout << endl;
    char replay;
    cout << "Play again? [y/n]" << endl;
    cin >> replay;
    if (replay == 'y'){
      condition = true; //continue
    }
    else{
      break;  //breaks while loop 
    }
  }
  return 0;
}

