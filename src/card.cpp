#include "card.h"
#include <iostream>

std::string rarityToString(Rarity rarity) {
    switch (rarity) {
        case Rarity::ORDINARY: return "Ordinary";
        case Rarity::RARE: return "Rare";
        case Rarity::EPIC: return "Epic";
        case Rarity::LEGENDARY: return "Legendary";
        default: return "Unknown";
    }
}

std::string cardTypeToString(CardType type) {
    switch (type) {
        case CardType::NINJA: return "Ninja";
        case CardType::WIZARD: return "Wizard";
        case CardType::ARCHER: return "Archer";
        case CardType::KNIGHT: return "Knight";
        case CardType::BISHOP: return "Bishop";
        default: return "Unknown";
    }
}

std::string superPowerToString(SuperPower power) {
    switch (power) {
        case SuperPower::FIRE: return "Fire";
        case SuperPower::FREEZE: return "Freeze";
        case SuperPower::STORM: return "Storm";
        case SuperPower::NONE: return "None";
        default: return "Unknown";
    }
}


void Card::printCard() {
    std::cout << "Rarity: " << rarityToString(rarity) << std::endl;
    std::cout << "Type: " << cardTypeToString(type) << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Mana: " << mana << std::endl;
}

std::string Card::toString() {
    return rarityToString(rarity) + " " + cardTypeToString(type) + " (" + std::to_string(health) + " HP, " + std::to_string(strength) + " STR)";
}

bool operator==(const Card& a, const Card& b) {
    return a.rarity == b.rarity && a.type == b.type;
}

Rarity upgradeRarity(Rarity rarity) {
    switch (rarity) {
        case Rarity::ORDINARY: return Rarity::RARE;
        case Rarity::RARE: return Rarity::EPIC;
        case Rarity::EPIC: return Rarity::LEGENDARY;
        case Rarity::LEGENDARY: return Rarity::LEGENDARY;
        default: return Rarity::ORDINARY;
    }
}
