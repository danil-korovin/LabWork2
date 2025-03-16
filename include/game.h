#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game {
public:
    Game();
    void playPvP();
    void playPvE();
    void loadGame();
    void saveGame();
    void showHighScores();

private:
    void dealInitialHands(Player& player1, Player& player2);
    Card generateRandomCard();
    void playerTurn(Player& player, Player& opponent);
};

#endif
