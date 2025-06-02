/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#include "player.h"
#include <iostream>

// Constructor of the Player class
Player::Player(std::string name):
    name(name),
    score(0),
    currentSuperPower(SuperPower::NONE),
    mana(0) {}

void Player::drawCard(const Card& card)
{
    // Adding a copy of the card to the vector
    hand.push_back(card);
}

void Player::playCard(size_t cardIndex, Player& opponent, size_t targetCardIndex)
{
    //Checking card indexes
    if (cardIndex >= hand.size() || targetCardIndex >= opponent.hand.size())
    {
        std::cout << "Wrong card index." << std::endl;
        return;
    }

    // Get links to attacking and defending cards
    Card& attackingCard = hand[cardIndex];
    Card& defendingCard = opponent.hand[targetCardIndex];

    std::cout << name << " using " << attackingCard.toString()
              << " attacks " << defendingCard.toString() << std::endl;
    // Dealing damage
    defendingCard.health -= attackingCard.strength;
    std::cout << "Card " << defendingCard.toString() << " received " << attackingCard.strength << " damage." << std::endl;
    // Increasing mana
    attackingCard.mana++;
    addMana(1);
    // Checking for card destruction
    if (defendingCard.health <= 0)
    {
        std::cout << "Card " << defendingCard.toString() << " is destroyed!" << std::endl;
        opponent.hand.erase(opponent.hand.begin() + targetCardIndex);
        addScore(100);
    }
}

void Player::printHand()
{
    //Display the cards
    std::cout << name << "'s hand:" << std::endl;
    for (size_t i = 0; i < hand.size(); ++i)
    {
        std::cout << i + 1 << ": " << hand[i].toString() << std::endl;
    }
}

int Player::getScore() const
{
    return score;
}

std::string Player::getName() const
{
    return name;
}

void Player::addScore(int points)
{
    score += points; //Adding points
}

bool Player::canMergeCards(size_t cardIndex1, size_t cardIndex2) const
{
    //Checking card indexes
    if (cardIndex1 >= hand.size() || cardIndex2 >= hand.size())
    {
        return false;
    }
    if (cardIndex1 == cardIndex2)
    {
        return false;
    }
    return hand[cardIndex1] == hand[cardIndex2];
}

bool Player::mergeCards(size_t cardIndex1, size_t cardIndex2)
{
    //Checking for card merge
    if (!canMergeCards(cardIndex1, cardIndex2))
    {
        std::cout << "It's impossible to combine these cards." << std::endl;
        return false;
    }
    // Get a link to the first card
    Card& card1 = hand[cardIndex1];
    card1.rarity = upgradeRarity(card1.rarity);
    card1.health *= 2;
    card1.strength *= 2;
    // Deleting the second card
    hand.erase(hand.begin() + cardIndex2);
    std::cout << name << " combined cards!  New card: " << card1.toString() << std::endl;
    addScore(50);
    return true;
}

void Player::useSuperPower(SuperPower power, Player& opponent)
{
    //Checking mana
    if (mana < 5)
    {
        std::cout << "Not enough mana to use superpower." << std::endl;
        return;
    }
    std::cout << name << " used " << superPowerToString(power) << "!" << std::endl;
    if (power == SuperPower::FIRE)
    {
        //Fire reduces a random card's health by 50%.
        if (!opponent.hand.empty())
        {
            int randomIndex = rand() % opponent.hand.size();
            opponent.hand[randomIndex].health /= 2;
            std::cout << "Opponent's card " << opponent.hand[randomIndex].toString() << " took damage!" << std::endl;
            if (opponent.hand[randomIndex].health <= 0)
            {
                std::cout << "The opponent's card is destroyed!" << std::endl;
                opponent.hand.erase(opponent.hand.begin() + randomIndex);
                addScore(100);
            }
        }
        else
        {
            std::cout << "Opponent has no cards." << std::endl;
        }
    }
    else if (power == SuperPower::FREEZE)
    {
        //FREEZE reduces all opponent's cards by 5 xp
        for (Card& card : opponent.hand)
        {
            card.strength -= 5;
            std::cout << "Opponent's card " << card.toString() << " lost 5 power!" << std::endl;
        }
    }
    else if (power == SuperPower::STORM)
    {
        //Storm reduces all opponent's cards by 10 xp
        for (Card& card : opponent.hand)
        {
            card.health -= 10;
            std::cout << "Opponent's card " << card.toString() << " took damage!" << std::endl;
        }
    }
    else
    {
        std::cout << "An unknown superpower." << std::endl;
        return;
    }

    mana -= 5;
    resetMana(); //Reset mana
}

int Player::getMana() const
{
    return mana;
}

void Player::addMana(int amount)
{
    mana += amount;
    if (mana > 5)
    {
        mana = 5;
    }
}

void Player::resetMana()
{
    mana = 0;
}

bool Player::canUseSuperPower() const
{
    return mana >= 5;
}
