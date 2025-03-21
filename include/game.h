#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game {
public:
    Game(); // Конструктор класса Game.
    void playPvP(); // Запускает PvP
    void playPvE(); // Запускает PvE
    void loadGame(); // Загружает сохраненную игру 
    void saveGame(); // Сохраняет текущее состояние
    void showHighScores(); // Показывает рекорды
    
private:
    void dealInitialHands(Player& player1, Player& player2); // Раздает начальные карты игрокам. Принимает ссылки на объекты Player.
    Card generateRandomCard();  // Генерирует случайную карту. Возвращает объект Card.
    void playerTurn(Player& player, Player& opponent); // Реализует ход игрока. Принимает ссылки на игроков.
    void AI(Player& player, Player& opponent); // Реализует ход компьютера. Принимает ссылки на игроков.
};

#endif
