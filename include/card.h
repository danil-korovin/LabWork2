/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#ifndef CARD_H
#define CARD_H
#include <string>
//For a limited set of named values use the enum class
// Enumeration for the rarity of the cards.
enum class Rarity
{
    ORDINARY,
    RARE,
    EPIC,
    LEGENDARY
};

// Enumeration for card types.
enum class CardType
{
    NINJA,
    WIZARD,
    ARCHER,
    KNIGHT,
    BISHOP
};

// Enumeration for superpowers.
enum class SuperPower
{
    NONE,
    FIRE,
    FREEZE,
    STORM
};

// Functions for converting values to strings.
std::string rarityToString(Rarity rarity);
std::string cardTypeToString(CardType type);
std::string superPowerToString(SuperPower power);

// The structure for the card representation.
class Card
{
public:
    Rarity rarity;
    CardType type;
    int health;
    int strength;
    int mana;

    // Constructor for initializing the Card object.
    Card(Rarity r, CardType t, int h, int s) :
        rarity(r),
        type(t),
        health(h),
        strength(s),
        mana(0) {}
    // A function for displaying information about the card.
    void printCard();
    // A function for converting map information into a string
    std::string toString();
};
// An operator for comparing two maps.
bool operator==(const Card& a, const Card& b);

// The function of improving the rarity of the card.
Rarity upgradeRarity(Rarity rarity);

#endif
