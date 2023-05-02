#ifndef DEALER_H
#define DEALER_H
#include <iomanip>
#include "CardCollection.h"
using namespace std;
// Dealer class 
class Dealer {
  private:
      // Card collection for the dealer cards
    CardCollection dealer_cards;
    // A reference to the main standard deck
    CardCollection &standard_deck;
    // Dealer hit if less than number
    static const int max_hit = 17;
    // Standing or not
    bool standing = false;
  public:
    // Constructor 
    Dealer(CardCollection & s_d);
    // Hit and stand 
    void hit();
    void stand();
    // Display hand info each turn  
    void displayInfo();
    // Does dealers turn
    void doTurn();
    // Is standing or not 
    bool isStanding() 
    {
      return standing;
    }
    // Gets total value 
    int getTotal()
    {
      return dealer_cards.getTotalValue();
    }
    // Display card description summary, used for printing to the file 
    string getCardsDescription();
};
#endif