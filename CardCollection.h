#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
using namespace std;
// Number of face value cards of a particular suit in a deck
static const int FACE_CARD_NUM = 9;
// CardCollection class which is used for deck and dealer/player cards 
class CardCollection {
  private:
    // Stores vector of cards 
    vector<Card> cards;
  public:
    // Deck constructor
    CardCollection() 
    {
      cout << "CardCollection constructor called!" << endl;
    }
    // Destructor
    ~CardCollection() 
    {
      cout << "CardCollection destructor called!" << endl;
    }
    // Adds a card 
    void addCard(Card card) 
    {
      cards.push_back(card);
    }
    // Removes a card at index 
    void removeCardAt(int index) 
    {
      cards.erase(cards.begin() + index);
    }
    // Gets the value of a card at index
    Card getCardAt(int index) 
    {
      return cards.at(index);
    }
    // Get collection size
    int getSize() 
    {  
      return cards.size();
    }
    // Clears the vector of cards 
    void reset() 
    {
      cards.clear();
    }
    // Get total value of all the cards
    int getTotalValue();
};

// Generates a standard deck of cards 
void generateStandardDeck(CardCollection & collection);
// Gets and removes a random card 
Card drawRandomCard(CardCollection & collection);
#endif