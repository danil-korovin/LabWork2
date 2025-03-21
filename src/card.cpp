/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#include "card.h"
#include <iostream>

//Функция преобразования Rarity в строку
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
        return "Unknown"; //Добавляем доп значение, чтобы избежать ошибки
    }
}

// Функция преобразования CardType в строку
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
        return "Unknown"; //Добавляем доп значение, чтобы избежать ошибки
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
        return "Unknown"; //Добавляем доп значение, чтобы избежать ошибки
    }
}

//Для проверки созданной карты
void Card::printCard()
{
    std::cout << "Rarity: " << rarityToString(rarity) << std::endl;
    std::cout << "Type: " << cardTypeToString(type) << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Mana: " << mana << std::endl;
}

//Вывод информации о карте
std::string Card::toString()
{
    return rarityToString(rarity) + " " + cardTypeToString(type) + " (" + std::to_string(health) + " HP, " + std::to_string(strength) + " POWER)";
}

// Перегрузка оператора == для сравнения двух объектов Card
bool operator==(const Card& a, const Card& b)
{
    return a.rarity == b.rarity && a.type == b.type;
}

// Перегрузка оператора == для сравнения двух объектов Card
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

