/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
public:
    Game(); // Constructor of the Game class.
    void playPvP(); 
    void playPvE(); 
    void loadGame(); 
    void saveGame(); 
    void showHighScores(); 
    void dealInitialHands(Player& player1, Player& player2); // Distributes the initial cards to the players. Accepts references to Player objects.
    Card generateRandomCard();  // Generates a random card. Returns the Card object.

private:
    
    void playerTurn(Player& player, Player& opponent); // Implements the player's move. Accepts links to players.
    void AI(Player& player, Player& opponent); // Implements the computer's progress. Accepts links to players.
};

#endif
