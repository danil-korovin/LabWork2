/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

class Player
{
public:
    std::vector<Card> hand;
    std::string name;
    int score;
    SuperPower currentSuperPower;
    int mana;
    Player(std::string name); // Constructor of the Player class
    void drawCard(const Card& card); // Adds a card to the player
    void playCard(size_t cardIndex, Player& opponent, size_t targetCardIndex);  // Attacking with an opponent's card
    void printHand(); // Displays cards on the screen
    bool canMergeCards(size_t cardIndex1, size_t cardIndex2) const; // Checks if the player can combine two cards.
    bool mergeCards(size_t cardIndex1, size_t cardIndex2); // Combines two player's cards.
    void useSuperPower(SuperPower power, Player& opponent);  // Uses a superpower.
    int getScore() const; // Returns the player's current score.
    std::string getName() const;  // Returns the player's name.
    int getMana() const;  // Returns the current amount of mana
    void addMana(int amount); // Adds mana to the player
    void resetMana(); //Drops the player's mana
    bool canUseSuperPower() const; // Checks if the player can use his superpower.
    void addScore(int points); // Adds points to the player's score.

};

#endif
