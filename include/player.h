#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

class Player {
public:
    std::vector<Card> hand;
    int score;
    std::string name;
    SuperPower currentSuperPower;
    int mana;

    Player(std::string name);
    void drawCard(const Card& card);
    void playCard(size_t cardIndex, Player& opponent, size_t targetCardIndex);  // Атака картой
    void printHand();
    bool canMergeCards(size_t cardIndex1, size_t cardIndex2) const;
    bool mergeCards(size_t cardIndex1, size_t cardIndex2);
    void useSuperPower(SuperPower power, Player& opponent);

    int getScore() const;
    std::string getName() const;
    int getMana() const;
    void addMana(int amount);
    void resetMana();
    bool canUseSuperPower() const;

    void addScore(int points);
private:
};

#endif
