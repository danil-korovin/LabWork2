/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#include <iostream>
#include "game.h"

int main()
{
    Game game;
    int choice;

    while (true)
    {
        std::cout << "Welcome to the 'CARD GAME'" << std::endl;
        std::cout << std::endl;
        std::cout << "Main rules of the game:" << std::endl;
        std::cout << "You and your opponent each get 7 cards." << std::endl;
        std::cout << "You need to destroy all of your opponent's cards." << std::endl;
        std::cout << "You can combine cards, attack cards, and use super powers." << std::endl;
        std::cout << "You get points for combining cards and destroying your opponent's cards." << std::endl;
        std::cout << "Have a good game!" << std::endl;
        std::cout << std::endl;
        std::cout << "Select the mode:"<< std::endl;
        std::cout << "1. PvP" << std::endl;
        std::cout << "2. PvE" << std::endl;
        std::cout << "3. Load game" << std::endl;
        std::cout << "4. Records" << std::endl;
        std::cout << "5. Save game" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cin >> choice;

        if (choice == 1)
        {
            game.playPvP();
        }
        else if (choice == 2)
        {
            game.playPvE();
        }
        else if (choice == 3)
        {
            game.loadGame();
        }
        else if (choice == 4)
        {
            game.showHighScores();
        }
        else if (choice == 5)
        {
            game.saveGame();
        }
        else if (choice == 6)
        {
            return 0;
        }
        else
        {
            std::cout << "Wrong choice." << std::endl;
        }
    }

    return 0;
}
