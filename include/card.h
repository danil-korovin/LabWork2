/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#ifndef CARD_H
#define CARD_H
#include <string>
//Для ограниченного набора именнованных значений используем enum class
// Перечисление для редкости карт.
enum class Rarity
{
    ORDINARY,
    RARE,
    EPIC,
    LEGENDARY
};

// Перечисление для типов карт.
enum class CardType
{
    NINJA,
    WIZARD,
    ARCHER,
    KNIGHT,
    BISHOP
};

// Перечисление для суперспособностей.
enum class SuperPower
{
    NONE,
    FIRE,
    FREEZE,
    STORM
};

// Функции для преобразования значений в строки.
std::string rarityToString(Rarity rarity);
std::string cardTypeToString(CardType type);
std::string superPowerToString(SuperPower power);

// Структуру для представления карты.
class Card
{
public:
    Rarity rarity;
    CardType type;
    int health;
    int strength;
    int mana;

    // Конструктор для инициализации объекта Card.
    Card(Rarity r, CardType t, int h, int s) :
        rarity(r),
        type(t),
        health(h),
        strength(s),
        mana(0) {}
    // Функция для вывода информации о карте.
    void printCard();
    // Функция для преобразования информации о карте в строку
    std::string toString();
};
// Оператор для сравнения двух карт.
bool operator==(const Card& a, const Card& b);

// Функция улучшения редкости карты.
Rarity upgradeRarity(Rarity rarity);

#endif
