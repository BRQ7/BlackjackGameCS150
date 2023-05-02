#ifndef CARD_H
#define CARD_H
// Card.h -
#include <iostream>
using namespace std;
// Enum for each card suit
enum CardSuit { DIAMOND, CLUB, HEART, SPADE };
// Card ranks, king, queen, and jack count as 10, ace counts as 11 and face counts as value
enum CardRank { KING, QUEEN, JACK, ACE, FACE};
// Card class 
class Card 
{
private:
  // The value, and the description of the card 
  int value;
  string description;
public:
  // Number of card suits, static and constant 
  const static int CARD_SUITS = 4;
  // Constructor 
  Card(CardSuit s, CardRank r, int v = 10);

  // Inline getters
  string getDescription() 
  { 
    return description; 
  }
  int getValue() 
  { 
    return value; 
  }
  // Setters
  void setDescription(string d);
  void setValue(int v);
};
#endif