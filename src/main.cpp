#include <iostream>
#include "game.h"

int main() {
    Game game;
    int choice;

    while (true) {
        std::cout << "Карточная игра" << std::endl;
        std::cout << "1. PvP" << std::endl;
        std::cout << "2. PvE" << std::endl;
        std::cout << "3. Загрузить игру" << std::endl;
        std::cout << "4. Рекорды" << std::endl;
        std::cout << "5. Сохранение" << std::endl;
        std::cout << "6. Выход" << std::endl;
        std::cout << "Выберите режим: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                game.playPvP();
                break;
            case 2:
                game.playPvE();
                break;
            case 3:
                game.loadGame();
                break;
            case 4:
                game.showHighScores();
                break;
            case 6:
                return 0;
                break;
            default:
                std::cout << "Неверный выбор." << std::endl;
        }
    }

    return 0;
}
