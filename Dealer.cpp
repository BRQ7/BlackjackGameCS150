#include "Dealer.h"
Dealer::Dealer(CardCollection & s_d) : standard_deck(s_d)
{
  // Draws the two random cards 
  Card card1 = drawRandomCard(standard_deck);
  Card card2 = drawRandomCard(standard_deck);
  // Adds the two random cards to the player deck
  dealer_cards.addCard(card1);
  dealer_cards.addCard(card2);
}
// Hit
void Dealer::hit()
{
  cout << "Dealer hit." << endl;
  dealer_cards.addCard(drawRandomCard(standard_deck));
  
}
// Stand 
void Dealer::stand()
{
  standing = true; 
  cout << "Dealer stood." << endl;
}
// Hits
void Dealer::doTurn() 
{
  // Hits if less than the max hit value 
  if(dealer_cards.getTotalValue() <= max_hit) 
  {
    hit();
  }
  else 
  {
    stand();
  }
}
// Displays the information about the dealer each turn 
void Dealer::displayInfo() 
{
  // Display cards, does not display first card as the dealer hides that one 
  cout << "Dealer's visible hand:" << endl;
  for(int i = 1; i < dealer_cards.getSize(); i++) 
  {
    // Formatted I/O requirement (also in Player.cpp)
    cout << "#" << right << i << left << setw(5) << " " << setw(20) << dealer_cards.getCardAt(i).getDescription() << endl;
  }
  // Display total 
  cout << "Dealer has a total of " << dealer_cards.getTotalValue() << endl;
}
string Dealer::getCardsDescription() 
{
  string description;
  // Iterates through cards getting description and appending it 
  for(int i = 0; i < dealer_cards.getSize(); i++)
  {
  // Final card 
    if(i == dealer_cards.getSize() - 1) 
    {
      description += dealer_cards.getCardAt(i).getDescription();
    }
    // Other cards have commas at end 
    else
    {
      description += dealer_cards.getCardAt(i).getDescription() + ", ";
    }
  }
  return description;
}