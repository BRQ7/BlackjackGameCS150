#ifndef PLAYER_H
#define PLAYER_H
#include <iomanip>
#include "Card.h"
#include "CardCollection.h"
using namespace std;
// Player class
class Player {
private:
  // Card collection for the player cards
  CardCollection player_cards;
  // A reference to the main standard deck
  CardCollection &standard_deck;
  // Standing 
  bool standing = false;
public:
  // Constructor that takes the first two cards
  Player(CardCollection &s_d);
  // Adds a card to the players collection

  // Hit and stand 
  void hit();
  void stand();
  // Display information about the player hand 
  void displayInfo(); 
  // Is standing or not 
  bool isStanding() 
  {
    return standing;
  }
  // Gets total value 
  int getTotal()
  {
    return player_cards.getTotalValue();
  }
  // Display card description summary, used for printing to the file 
  string getCardsDescription();
};
#endif