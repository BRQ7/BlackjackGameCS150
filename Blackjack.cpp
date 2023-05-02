 /* Blackjack.cpp - Blackjack game written in C++ for the CS final project 
   * Author:     Brandon Q
   * Mo dule:     15
   * Project:    Project #1
   * Problem Statement : Make a blackjack game that meets all the requirements of the CS150 final project, and have replayability features, proper rules, etc.
   * Tutorial:
Blackjack is a game in which you compete against a dealer. At the beginning of the game, both the dealer and the player are dealed 2 cards by the dealer. Only one of the dealer's cards is visible to the player. Royal cards count as 10, aces count as 11, and face value cards count as their value. Each turn the player must choose to stand or hit. If they hit, they get dealed an additional card. If they go over 21, they bust and the dealer wins. If they stand, they stop getting dealed cards. The dealer only can hit if they have less than a total value of 17. The dealer will also bust if they exceed the 21 value limit. In case where neither the dealer or player bust, the person with a closer total value to 21 will win. If they have an equal value the game results in a draw.
   * Algorithim :
   * 1. Make heavy use of object oriented programming primarily for reusability, use a card class, card collection which is a collection of card objects, and dealer and player 
   * 2.  In main, use control flow such as while loops and if statements to verify user input is valid and then perform the corresponding action 
   * 3. Use vectors in card collection to have a non-fixed number of cards and use the various vector functions such as push_back along with for loops to calculate stuff like total value of the card collection
   * 4. Have dealer AI programmed to only hit if past 17
   * 5. Use a series if else if else statements at the end of players turn sequence and dealers turn sequence to check for a winner and looser 
   * 6. Use IO manipulators to cleanly tell the player their current turn state 
   * 7. Use file IO for game statistics so player can learn from their game
   */
#include <iostream>
#include <fstream>
#include "CardCollection.h"
#include "Player.h"
#include "Dealer.h"
using namespace std; 
// Displays tutorial
void displayTutorial();
// Gets a choice with validation
char getValidChoice();
// Displays game over, draw, and win 
void displayWin(int player_turns, int total_turns, int player_total, int dealer_total, string player_hand, string dealer_hand);
void displayGameover();
void displayDraw();
// Checks if player wants to play again
void playAgain();
// File name for game statistics, File I/O requirement
static const string FILE_NAME = "gamestatistics.txt";
int main() 
{
  // Max value in blackjack 
  const int MAX_VALUE = 21;
  // Ensures proper random number generation 
  srand(time(0));
  // Generates standard deck 
  CardCollection deck;
  generateStandardDeck(deck);
  // Welcome message and subsequent tutorial 
  cout << "Welcome to blackjack!" << endl;
  displayTutorial();
  // Main gameloop
  while(true) 
  {
    // Turn, and total turn counter used in file i/o
    int player_turns = 0, total_turns = 0;
    cout << "Game started." << endl;
    // Intializes player and dealer 
    Player player(deck);
    Dealer dealer(deck);

    // Player goes until they stand or loose the game, or got 21  
    while(!player.isStanding() && player.getTotal() < MAX_VALUE) 
    {
      // Increment total turns 
      total_turns++;
      player.displayInfo();
  
      char choice = getValidChoice();
      if(choice == 'h') 
      {
        player.hit();
      }
      else 
      {
        player.stand();
      }
    }
    // Gets correct number of total turns 
    player_turns = total_turns;
    player.displayInfo();
    if(player.getTotal() > MAX_VALUE) 
    {
      displayGameover(); 
      playAgain();
      continue;
    }
    else if(player.getTotal() == 21) 
    {
      cout << "You got 21!" << endl;
       displayWin(player_turns, total_turns, player.getTotal(), dealer.getTotal(),  player.getCardsDescription(), dealer.getCardsDescription());

      playAgain();
      continue;
    }

    // Dealer goes until they stand or loose the game 
    while(!dealer.isStanding() && dealer.getTotal() <= MAX_VALUE) 
    {
      total_turns++;
      dealer.displayInfo();
      dealer.doTurn();
    }
    dealer.displayInfo();
    // Dealer bust 
    if(dealer.getTotal() > MAX_VALUE) 
    {
      cout << "Dealer bust!" << endl;
      displayWin(player_turns, total_turns, player.getTotal(), dealer.getTotal(),  player.getCardsDescription(), dealer.getCardsDescription());
    }
    // Draw 
    else if(player.getTotal() == dealer.getTotal()) 
    {
      displayDraw();
    }
    // Dealer has a higher value than the player 
    else if(dealer.getTotal() > player.getTotal()) 
    {
      cout << "Dealer cards are at a higher value than your cards" << endl;
      displayGameover();
    }
    // Dealer has a lesser value than player 
    else if(dealer.getTotal() < player.getTotal()) 
    {
      cout << "Your cards have a higher value than the dealers" << endl;
       displayWin(player_turns, total_turns, player.getTotal(), dealer.getTotal(),  player.getCardsDescription(), dealer.getCardsDescription());
    }
    playAgain();
  }
}
// Tutorial 
void displayTutorial() 
{
  cout << "Blackjack is a game in which you compete against a dealer. At the beginning of the game, both the dealer and the player are dealed 2 cards by the dealer. Only one of the dealer's cards is visible to the player. Royal cards count as 10, aces count as 11, and face value cards count as their value. Each turn the player must choose to stand or hit. If they hit, they get dealed an additional card. If they go over 21, they bust and the dealer wins. If they stand, they stop getting dealed cards. The dealer only can hit if they have less than a total value of 17. The dealer will also bust if they exceed the 21 value limit. In case where neither the dealer or player bust, the person with a closer total value to 21 will win. If they have an equal value the game results in a draw. "<< endl;
}
// Gets validated choice 
char getValidChoice() 
{
  char input;
  // Loops until valid choice 
  while(true) 
  {
    // Prompts and gets input, case insenstive
    cout << "Would you like to hit (h) or stand (s)? ";
    cin >> input;
    input = tolower(input);
    // Validates input 
    if(input == 'h' || input == 's') 
    {
      return input;
    }
    else 
    {
      cout << "Please must enter a valid input (h or s)." << endl;
    }
  }
}
// Gameover 
void displayGameover() 
{
  cout << "You busted!" << endl;
}
// Win
void displayWin(int player_turns, int total_turns, int player_total, int dealer_total, string player_hand, string dealer_hand) 
{
  cout << "You won!" << endl;
  // Check if player wants to document the win 
  cout << "Want to overwrite the win statistics record file(Y)? ";
  char choice;
  cin >> choice;
  choice = tolower(choice);
  // Leave function if not writing to file 
  if(choice != 'y') 
  {
    cout << "Not saving record to file." << endl;
    return;
  }
  // Open output file 
  ofstream output_file;
  output_file.open(FILE_NAME);
  // Writes all record information to the file 
  output_file << "Game Statistics" << endl;
  output_file << "Final Player Value: " << player_total << endl;
 output_file << "Final Dealer Value: " << dealer_total << endl;
  output_file << "Final Player Hand: " << player_hand << endl;
  output_file << "Final Dealer Hand: " << dealer_hand << endl;
  output_file << "Player Turns: " << player_turns << endl;
  output_file << "Dealer Turns: " << total_turns - player_turns << endl;
  output_file << "Total Turns: " << total_turns << endl;

  // Close file 
  output_file.close();
}
// Draw 
void displayDraw() 
{
  cout << "You have the same value as the dealer, you drawed!" << endl;
}
// Checks if player wants to play again 
void playAgain() 
{
  // Asks player if they want to palyer again 
  cout << "Want to play again (Y)? ";
  char choice;
  cin >> choice;
  choice = tolower(choice);
  // Player does not want to play again 
  if(choice != 'y') 
  {
    cout << "Thank you for playing blackjack!" << endl;
    exit(0);
  }
}
