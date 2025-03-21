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
    Player(std::string name); // Конструктор класса Player
    void drawCard(const Card& card); // Добавляет карту игроку
    void playCard(size_t cardIndex, Player& opponent, size_t targetCardIndex);  // Атака картой противника
    void printHand(); // Выводит на экран карты
    bool canMergeCards(size_t cardIndex1, size_t cardIndex2) const; // Проверяет, может ли игрок объединить две карты
    bool mergeCards(size_t cardIndex1, size_t cardIndex2); // Объединяет две карты игрока.
    void useSuperPower(SuperPower power, Player& opponent);  // Использует суперспособность.
    int getScore() const; // Возвращает текущий счет игрока.
    std::string getName() const;  // Возвращает имя игрока.
    int getMana() const;  // Возвращает текущее количество маны у игрока
    void addMana(int amount); // Добавляет ману игроку
    void resetMana(); // Сбрасывает ману игрока
    bool canUseSuperPower() const; // Проверяет, может ли игрок использовать свою суперспособность
    void addScore(int points); // Добавляет очки к счету игрока.

};

#endif
