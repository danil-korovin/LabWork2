/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

Game::Game()
{
    srand(time(0)); // задаём генератор случайных чисел на основе текущего времени
}

void Game::playPvP()
{
    //Создаём игроков
    Player player1("Player 1");
    Player player2("Player 2");
    //Раздаём карты игрокам
    dealInitialHands(player1, player2);
    //Определяем чей ход
    while (!player1.hand.empty() && !player2.hand.empty())
    {
        playerTurn(player1, player2);
        if (!player2.hand.empty() && !player1.hand.empty())
        {
            playerTurn(player2, player1);
        }
    }
    //Определяем победителя
    if (player1.hand.empty())
    {
        std::cout << player2.getName() << " wins!" << std::endl;
    }
    else
    {
        std::cout << player1.getName() << " wins!" << std::endl;
    }

    std::cout << player1.getName() << " Score: " << player1.getScore() << std::endl;
    std::cout << player2.getName() << " Score: " << player2.getScore() << std::endl;
}

void Game::playPvE()
{
    //Создаём игроков
    Player player1("Player 1");
    Player player2("CPU");
    //Раздаём карты игрокам
    dealInitialHands(player1, player2);
    //Определяем чей ход
    while (!player1.hand.empty() && !player2.hand.empty())
    {
        playerTurn(player1, player2);
        if (!player2.hand.empty() && !player1.hand.empty())
        {
            AI(player2, player1);
        }
    }
    //Определяем победителя
    if (player1.hand.empty())
    {
        std::cout << player2.getName() << " wins!" << std::endl;
    }
    else
    {
        std::cout << player1.getName() << " wins!" << std::endl;
    }

    std::cout << player1.getName() << " Score: " << player1.getScore() << std::endl;
    std::cout << player2.getName() << " Score: " << player2.getScore() << std::endl;
}

void Game::loadGame()
{

    std::cout << "Load game not ready yet." << std::endl;
}

void Game::saveGame()
{

    std::cout << "Save game not ready yet." << std::endl;
}

void Game::showHighScores()
{
    std::cout << "High scores not ready yet." << std::endl;
}
//Добавление карт игрокам
void Game::dealInitialHands(Player& player1, Player& player2)
{
    for (int i = 0; i < 7; ++i)
    {
        player1.drawCard(generateRandomCard());
        player2.drawCard(generateRandomCard());
    }
}
//Случайная генерация карт
Card Game::generateRandomCard()
{
    Rarity rarity = static_cast<Rarity>(rand() % 4); //Случайная редкость
    CardType type = static_cast<CardType>(rand() % 5); //Случайный тип карты
    int health;
    int strength;
    // Баллансируем случайную генерацию карты
    if (rarity == Rarity::ORDINARY)
    {
        health = rand() % 30 + 20;
        strength = rand() % 10 + 5;
    }
    else if (rarity == Rarity::RARE)
    {
        health = rand() % 30 + 40;
        strength = rand() % 10 + 10;
    }
    else if (rarity == Rarity::EPIC)
    {
        health = rand() % 30 + 60;
        strength = rand() % 10 + 15;
    }
    else if (rarity == Rarity::LEGENDARY)
    {
        health = rand() % 30 + 80;
        strength = rand() % 10 + 20;
    }

    return Card(rarity, type, health, strength); //Создаём и возвращаем карту
}
void Game::AI(Player& player, Player& opponent)
{
    if (player.canUseSuperPower())
    {
        SuperPower power;
        power = SuperPower::FIRE;
        int index1 = 1;
        size_t cardIndex1 = static_cast<size_t>(index1 - 1);
        std::cout << player.getName() << " uses superpower " << superPowerToString(power) << " to attack " << opponent.hand[cardIndex1].toString() << std::endl;
        //Применяем супер силу
        player.useSuperPower(power, opponent);
    }
    else
    {
        int index1 = 1;
        int index2 = 1;
        size_t cardIndex1 = static_cast<size_t>(index1 - 1);
        size_t cardIndex2 = static_cast<size_t>(index2 - 1);
        player.playCard(cardIndex1, opponent, cardIndex2); //атакуем соперника

    }
}
void Game::playerTurn(Player& player, Player& opponent)
{
    std::cout << "\n" << player.getName() << "'s turn:" << std::endl;
    //Выводит карты игрока
    player.printHand();
    std::cout << "Mana: " << player.getMana() << std::endl;
    std::cout << "" << std::endl;
    //Выводит карты соперника
    opponent.printHand();
    std::cout << "" << std::endl;
    std::cout << "Actions:" << std::endl;
    std::cout << "press (1, index1, index2) to attack card opponent's index2 card with your index1 card" << std::endl;
    std::cout << "press (2, index1, index2) to combine your index1 card and index2 card" << std::endl;
    std::cout << "press (3, index1) to use super power for opponent's index1 card (if your mana >= 5)" << std::endl;
    std::cout << "press 4 to show score" << std::endl;
    std::cout << "press 5 to save game" << std::endl;
    std::cout << "press 6 to exit game" << std::endl;
    int action;

    std::cin >> action;

    if (action == 1)
    {
        //Работаем с индексами карт
        int index1, index2;
        std::cin >> index1 >> index2;
        if (index1 <= 0 || index2 <= 0)
        {
            std::cout << "Card indexe must be bigger than 0." << std::endl;
            return;
        }
        // Преобразуем индексы в тип size_t и уменьшаем на единицу
        size_t cardIndex1 = static_cast<size_t>(index1 - 1);
        size_t cardIndex2 = static_cast<size_t>(index2 - 1);
        //Проверка индексов карт
        if (cardIndex1 < player.hand.size() && cardIndex2 < opponent.hand.size())
        {
            player.playCard(cardIndex1, opponent, cardIndex2); //атакуем соперника
        }
        else
        {
            std::cout << "Wrong card index." << std::endl;
        }
    }
    else if (action == 2)
    {
        //Повторяем тоже, что и в (action = 1)
        int index1, index2;
        std::cin >> index1 >> index2;
        if (index1 <= 0 || index2 <= 0)
        {
            std::cout << "Card indexe must be bigger than 0." << std::endl;
            return;
        }
        size_t cardIndex1 = static_cast<size_t>(index1 - 1);
        size_t cardIndex2 = static_cast<size_t>(index2 - 1);
        if (cardIndex1 < player.hand.size() && cardIndex2 < player.hand.size())
        {
            player.mergeCards(cardIndex1, cardIndex2); //объединяем карты
        }
        else
        {
            std::cout << "Wrong card index." << std::endl;
        }
    }
    else if (action == 3)
    {
        //Повторяем тоже, что и в (action = 1) только для одного индекса
        int index1;
        std::cin >> index1;
        if (index1 <= 0)
        {
            std::cout << "Card indexe must be bigger than 0." << std::endl;
            return;
        }
        size_t cardIndex1 = static_cast<size_t>(index1 - 1);
        if (cardIndex1 < opponent.hand.size())
        {
            if (player.canUseSuperPower())
            {
                int powerChoice;
                std::cout << "Choose a superpower:\n1. Fire\n2. Freeze\n3. Storm\n";
                std::cin >> powerChoice;
                //Выбираем супер силу
                SuperPower power;
                if (powerChoice == 1)
                {
                    power = SuperPower::FIRE;
                }
                else if (powerChoice == 2)
                {
                    power = SuperPower::FREEZE;
                }
                else if (powerChoice == 3)
                {
                    power = SuperPower::STORM;
                }
                else
                {
                    std::cout << "Wrong choice of superpower." << std::endl;
                    return;
                }
                std::cout << player.getName() << " uses superpower " << superPowerToString(power) << " to attack " << opponent.hand[cardIndex1].toString() << std::endl;
                //Применяем супер силу
                player.useSuperPower(power, opponent);
            }
            else
            {
                std::cout << "Not enough mana to use superpower." << std::endl;
            }
        }
        else
        {
            std::cout << "Wrong card index." << std::endl;
        }
    }
    else if (action == 4)
    {
        //Выводим счёт
        std::cout << player.getName() << " Score: " << player.getScore() << std::endl;
        std::cout << opponent.getName() << " Score: " << opponent.getScore() << std::endl;
    }
    else if (action == 5)
    {
        saveGame();
    }
    else if (action == 6)
    {
        //Выходим из игры
        std::cout << "Exit." << std::endl;
        exit(0);
    }
    else
    {
        //Проверяем верность ввода
        std::cout << "Wrong action. You missed your turn." << std::endl;
    }
}
