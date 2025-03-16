#ifndef CARD_H
#define CARD_H
#include <string>

enum class Rarity {
    ORDINARY,
    RARE,
    EPIC,
    LEGENDARY
};

enum class CardType {
    NINJA,
    WIZARD,
    ARCHER,
    KNIGHT,
    BISHOP
};

enum class SuperPower {
    NONE,
    FIRE,
    FREEZE,
    STORM
};

std::string rarityToString(Rarity rarity);
std::string cardTypeToString(CardType type);
std::string superPowerToString(SuperPower power);

struct Card {
    Rarity rarity;
    CardType type;
    int health;
    int strength;
    int mana;
    Card(Rarity r, CardType t, int h, int s) : 
    rarity(r), 
    type(t), 
    health(h), 
    strength(s), 
    mana(0) {}
    void printCard();
    std::string toString();
};

bool operator==(const Card& a, const Card& b);

Rarity upgradeRarity(Rarity rarity);

#endif
