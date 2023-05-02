#include "CardCollection.h"
// Gets a random card 
Card drawRandomCard(CardCollection & collection) {
  // Generates random index 
  int random_index = rand() % collection.getSize();
  // Gets the random card 
  Card random_card = collection.getCardAt(random_index);
  // Removes the card 
  collection.removeCardAt(random_index);
  return random_card;
}
// Generates a standard deck of cards which is length 52, setting the passed by reference deck to it
void generateStandardDeck(CardCollection & collection) 
{
  // Keeps track of current suit, starts with diamond 
  CardSuit current_suit = DIAMOND;
  // Iterates through the number of card suits 
  for(int i = 0; i < Card::CARD_SUITS; i++) 
  {
    switch(i) {
      case 1:
        current_suit = HEART;
        break;
      case 2:
        current_suit = SPADE;
        break;
      case 3:
        current_suit = CLUB;
        break;
    }
    // Special ranks 
    collection.addCard(Card(current_suit, KING));
    collection.addCard(Card(current_suit, QUEEN));
    collection.addCard(Card(current_suit, JACK));
    collection.addCard(Card(current_suit, ACE));
    // Adds all face value cards for a specific suit 
    for(int i = 1; i < FACE_CARD_NUM; i++) 
    {
      // Adds a face card value of the current suite of i + 1 (2-9)
      collection.addCard(Card(current_suit, FACE, i + 1));
    }
  }

}

// Gets total value by adding all cards 
int CardCollection::getTotalValue() {
  // Total
  int total = 0;
  // Iterates vector
  for(int i = 0; i < getSize(); i++) 
  {
    // Increments total 
    total += getCardAt(i).getValue();
  }
  return total;
}