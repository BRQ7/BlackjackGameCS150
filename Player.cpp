#include "Player.h"
// Player constructor, gets first two cards from the standard deck 
Player::Player(CardCollection & s_d) : standard_deck(s_d)
{
  // Draws the two random cards 
  Card card1 = drawRandomCard(standard_deck);
  Card card2 = drawRandomCard(standard_deck);
  // Adds the two random cards to the player deck
  player_cards.addCard(card1);
  player_cards.addCard(card2);
}

// Hit (gets new card)
void Player::hit() 
{
  // Tell user their choice 
  cout << "You hit." << endl;
  // Draws random card and adds it to the player's cards 
  Card card = drawRandomCard(standard_deck);
  player_cards.addCard(card);
  // Displays to user the drawed card and new total 
  cout << "You drew a " << card.getDescription() << endl;
}
// Stand (do nothing)
void Player::stand() 
{
  standing = true;
  // Tell user choice
  cout << "You stood." << endl;
}
// Displays the information about the player each turn 
void Player::displayInfo() 
{
  // Display cards 
  cout << "Your hand:" << endl;

  for(int i = 0; i < player_cards.getSize(); i++) 
  {
      // Formatted I/O requirement (also in Dealer.cpp)
      cout << "#" << right << i + 1 << left << setw(5) << " " << setw(20) << player_cards.getCardAt(i).getDescription() << endl;
  }
  // Display total 
  cout << "You have a total of " << player_cards.getTotalValue() << endl;

}
string Player::getCardsDescription() 
{
  string description;
  // Iterates through cards getting description and appending it 
  for(int i = 0; i < player_cards.getSize(); i++)
  {
    // Final card 
    if(i == player_cards.getSize() - 1) 
    {
      description += player_cards.getCardAt(i).getDescription();
    }
    // Other cards have commas at end 
    else
    {
      description += player_cards.getCardAt(i).getDescription() + ", ";
    }
  }
  return description;
}