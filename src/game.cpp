#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

Game::Game() {
    srand(time(0));
}

void Game::playPvP() {
    Player player1("Player 1");
    Player player2("Player 2");

    dealInitialHands(player1, player2);

    while (!player1.hand.empty() && !player2.hand.empty()) {
        playerTurn(player1, player2);
        if (!player2.hand.empty() && !player1.hand.empty()) {
            playerTurn(player2, player1);
        }
    }
    if (player1.hand.empty()) {
        std::cout << player2.getName() << " wins!" << std::endl;
    } else {
        std::cout << player1.getName() << " wins!" << std::endl;
    }

    std::cout << player1.getName() << " Score: " << player1.getScore() << std::endl;
    std::cout << player2.getName() << " Score: " << player2.getScore() << std::endl;
}

void Game::playPvE() {

    std::cout << "PvE mode not implemented yet." << std::endl;
}

void Game::loadGame() {

    std::cout << "Load game not implemented yet." << std::endl;
}

void Game::saveGame() {

    std::cout << "Save game not implemented yet." << std::endl;
}

void Game::showHighScores() {
    std::cout << "High scores not implemented yet." << std::endl;
}

void Game::dealInitialHands(Player& player1, Player& player2) {
    for (int i = 0; i < 7; ++i) {
        player1.drawCard(generateRandomCard());
        player2.drawCard(generateRandomCard());
    }
}

Card Game::generateRandomCard() {
    Rarity rarity = static_cast<Rarity>(rand() % 4);
    CardType type = static_cast<CardType>(rand() % 5);
    int health = rand() % 50 + 50; 
    int strength = rand() % 20 + 10; 
    return Card(rarity, type, health, strength);
}

void Game::playerTurn(Player& player, Player& opponent) {
    std::cout << "\n" << player.getName() << "'s turn:" << std::endl;
    player.printHand();
    std::cout << "Mana: " << player.getMana() << std::endl;

    int action, index1, index2;
    std::cout << "Введите действие (действие карта1 карта2): ";
    std::cin >> action >> index1 >> index2;

    if (index1 <= 0 || index2 <= 0) {
        std::cout << "Индексы карт должны быть больше 0." << std::endl;
        return;
    }

    size_t cardIndex1 = static_cast<size_t>(index1 - 1);
    size_t cardIndex2 = static_cast<size_t>(index2 - 1);

    switch (action) {
        case 1: { 
            if (cardIndex1 < player.hand.size() && cardIndex2 < opponent.hand.size()) {
                player.playCard(cardIndex1, opponent, cardIndex2);
            } else {
                std::cout << "Неверные индексы карт." << std::endl;
            }
            break;
        }
        case 2: { 
            if (cardIndex1 < player.hand.size() && cardIndex2 < player.hand.size()) {
                player.mergeCards(cardIndex1, cardIndex2);
            } else {
                std::cout << "Неверные индексы карт." << std::endl;
            }
            break;
        }
        case 3: { 
             if (cardIndex1 < player.hand.size() && cardIndex2 < opponent.hand.size()) {
                if (player.canUseSuperPower()) {
                    int powerChoice;
                    std::cout << "Выберите супер силу:\n1. Fire\n2. Freeze\n3. Storm\n";
                    std::cin >> powerChoice;

                    SuperPower power;
                    switch (powerChoice) {
                        case 1: power = SuperPower::FIRE; break;
                        case 2: power = SuperPower::FREEZE; break;
                        case 3: power = SuperPower::STORM; break;
                        default:
                            std::cout << "Неверный выбор супер силы." << std::endl;
                            return;
                    }
                    std::cout << player.getName() << " использует супер силу " << superPowerToString(power) << " картой " << opponent.hand[cardIndex2].toString() << std::endl;
                    player.useSuperPower(power, opponent);
                } else {
                    std::cout << "Недостаточно маны для использования супер силы." << std::endl;
                }
            } else {
                std::cout << "Неверные индексы карт." << std::endl;
            }
            break;
        }
        case 4: { 
            std::cout << player.getName() << " Score: " << player.getScore() << std::endl;
            break;
        }
        case 5: { 
            saveGame();
            break;
        }
        case 6: { 
            std::cout << "Выход из игры." << std::endl;
            exit(0);
        }
        default:
            std::cout << "Неверное действие." << std::endl;
            break;
    }
}
