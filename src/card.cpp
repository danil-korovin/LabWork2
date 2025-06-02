/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#include "card.h"
#include <iostream>

//The function of converting Rarity to a string
std::string rarityToString(Rarity rarity)
{
    if (rarity == Rarity::ORDINARY)
    {
        return "Ordinary";
    }
    else if (rarity == Rarity::RARE)
    {
        return "Rare";
    }
    else if (rarity == Rarity::EPIC)
    {
        return "Epic";
    }
    else if (rarity == Rarity::LEGENDARY)
    {
        return "Legendary";
    }
    else
    {
        return "Unknown"; //add an additional value to avoid an error
    }
}

// CardType to string conversion function
std::string cardTypeToString(CardType type)
{
    if (type == CardType::NINJA)
    {
        return "Ninja";
    }
    else if (type == CardType::WIZARD)
    {
        return "Wizard";
    }
    else if (type == CardType::ARCHER)
    {
        return "Archer";
    }
    else if (type == CardType::KNIGHT)
    {
        return "Knight";
    }
    else if (type == CardType::BISHOP)
    {
        return "Bishop";
    }
    else
    {
        return "Unknown"; //add an additional value to avoid an error
    }
}

std::string superPowerToString(SuperPower power)
{
    if (power == SuperPower::FIRE)
    {
        return "Fire";
    }
    else if (power == SuperPower::FREEZE)
    {
        return "Freeze";
    }
    else if (power == SuperPower::STORM)
    {
        return "Storm";
    }
    else if (power == SuperPower::NONE)
    {
        return "None";
    }
    else
    {
        return "Unknown"; //add an additional value to avoid an error.
    }
}

//check the created card
void Card::printCard()
{
    std::cout << "Rarity: " << rarityToString(rarity) << std::endl;
    std::cout << "Type: " << cardTypeToString(type) << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Mana: " << mana << std::endl;
}

//Displaying information about the card
std::string Card::toString()
{
    return rarityToString(rarity) + " " + cardTypeToString(type) + " (" + std::to_string(health) + " HP, " + std::to_string(strength) + " POWER)";
}

// Operator == for comparing two Card objects
bool operator==(const Card& a, const Card& b)
{
    return a.rarity == b.rarity && a.type == b.type;
}

// Operator == for comparing two Card objects
Rarity upgradeRarity(Rarity rarity)
{
    if (rarity == Rarity::ORDINARY)
    {
        return Rarity::RARE;
    }
    else if (rarity == Rarity::RARE)
    {
        return Rarity::EPIC;
    }
    else if (rarity == Rarity::EPIC)
    {
        return Rarity::LEGENDARY;
    }
    else if (rarity == Rarity::LEGENDARY)
    {
        return Rarity::LEGENDARY;
    }
    else
    {
        return Rarity::ORDINARY;
    }
}

