#include "player.h"
#include <iostream>

Player::Player(std::string name) : name(name), score(0),  currentSuperPower(SuperPower::NONE), mana(0) {}

void Player::drawCard(const Card& card) {
    hand.push_back(card);
}

void Player::playCard(size_t cardIndex, Player& opponent, size_t targetCardIndex) {
    if (cardIndex >= hand.size() || targetCardIndex >= opponent.hand.size()) {
        std::cout << "Неверные индексы карт." << std::endl;
        return;
    }

    Card& attackingCard = hand[cardIndex];
    Card& defendingCard = opponent.hand[targetCardIndex];

    std::cout << name << " атакует картой " << attackingCard.toString()
              << " карту " << defendingCard.toString() << std::endl;

    defendingCard.health -= attackingCard.strength;
    std::cout << "Карта " << defendingCard.toString() << " получила " << attackingCard.strength << " урона." << std::endl;

    attackingCard.mana++;
    addMana(1);

    if (defendingCard.health <= 0) {
        std::cout << "Карта " << defendingCard.toString() << " уничтожена!" << std::endl;
        opponent.hand.erase(opponent.hand.begin() + targetCardIndex);
        addScore(100);
    }
}

void Player::printHand() {
    std::cout << name << "'s hand:" << std::endl;
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i + 1 << ": " << hand[i].toString() << std::endl;
    }
}

int Player::getScore() const {
    return score;
}

std::string Player::getName() const {
    return name;
}

void Player::addScore(int points) {
    score += points;
}

bool Player::canMergeCards(size_t cardIndex1, size_t cardIndex2) const {
    if (cardIndex1 >= hand.size() || cardIndex2 >= hand.size()) {
        return false;
    }
    if (cardIndex1 == cardIndex2) {
        return false;
    }
    return hand[cardIndex1] == hand[cardIndex2];
}

bool Player::mergeCards(size_t cardIndex1, size_t cardIndex2) {
    if (!canMergeCards(cardIndex1, cardIndex2)) {
        std::cout << "Невозможно объединить эти карты." << std::endl;
        return false;
    }

    Card& card1 = hand[cardIndex1];

   
    card1.rarity = upgradeRarity(card1.rarity);
    
    card1.health += 20;
    card1.strength += 5;

    hand.erase(hand.begin() + cardIndex2);

    std::cout << name << " объединил карты!  Новая карта: " << card1.toString() << std::endl;
    addScore(50); 

    return true;
}

void Player::useSuperPower(SuperPower power, Player& opponent) {
    if (mana < 5) {
        std::cout << "Недостаточно маны для использования супер силы." << std::endl;
        return;
    }

    std::cout << name << " использует " << superPowerToString(power) << "!" << std::endl;

    switch (power) {
        case SuperPower::FIRE:
            if (!opponent.hand.empty()) {
                int randomIndex = rand() % opponent.hand.size();
                opponent.hand[randomIndex].health -= 30;
                std::cout << "Карта оппонента " << opponent.hand[randomIndex].toString() << " получила урон!" << std::endl;
                if (opponent.hand[randomIndex].health <= 0) {
                    std::cout << "Карта оппонента уничтожена!" << std::endl;
                    opponent.hand.erase(opponent.hand.begin() + randomIndex);
                    addScore(100);
                }
            } else {
                std::cout << "У оппонента нет карт." << std::endl;
            }
            break;
        case SuperPower::FREEZE:
            std::cout << "Оппонент заморожен и пропускает ход!" << std::endl;
            break;
        case SuperPower::STORM:
            for (Card& card : opponent.hand) {
                card.health -= 10;
                std::cout << "Карта оппонента " << card.toString() << " получила урон!" << std::endl;
            }
            break;
        default:
            std::cout << "Неизвестная супер сила." << std::endl;
            return;
    }

    mana -= 5;  
    resetMana();
}

int Player::getMana() const {
    return mana;
}

void Player::addMana(int amount) {
    mana += amount;
    if (mana > 5) {
        mana = 5; 
    }
}

void Player::resetMana() {
    mana = 0;
}

bool Player::canUseSuperPower() const {
    return mana >= 5;
}
