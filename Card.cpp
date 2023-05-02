#include "Card.h"
// Constructor for card, sets the suit, then the description, value is only passed if the card is non-face, rank and suit is not stored as its only used once for setting description
Card::Card(CardSuit s, CardRank r, int v) 
{
  // Suit name 
  string suit_name;
  // Gets proper suit name 
  switch(s) 
  {
    case DIAMOND :
      suit_name = "Diamonds";
      break;
    case HEART:
      suit_name = "Hearts";
      break;
    case SPADE:
      suit_name = "Spades";
      break;
    case CLUB:
      suit_name = "Clubs";
      break;
  }
  // Description variable 
  string desc;
  // Determines card desc and value (king, queen, and jack share value )
  switch(r) 
  {
    case KING:
      desc = "King";
      break;
    case QUEEN:
      desc = "Queen";
      break;
    case JACK:
      desc = "Jack";
      break;
    case ACE:
      desc = "Ace";
      v = 11; // Changes value for ace 
      break;
    case FACE:
      // Error if the value is left as default for face value cards 
      if(v == 10) 
      {
        cout << "Error: Face cards must be provided with a value!";
        exit(0);
      }
      char value_char = v + '0'; // Card description for face value cards begins with the card number 
      desc = value_char;
      break;
  }
  setValue(v);
  // All descriptions share this ending element 
  desc += " of " + suit_name;
  // Sets description 
  setDescription(desc);

}
// Sets description of the card
void Card::setDescription(string d) 
{
  description = d;
}
// Sets value of card, ensuring proper value 
void Card::setValue(int v)
{
  if(v < 0 || v > 11) 
  {
    cout << "Error: Card value must be 1-11." << endl;
    exit(0);
  }
  value = v;
}