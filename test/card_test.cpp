/* Korovin Danil st128737@student.spbu.ru
   LabWork2
*/
#include "gtest/gtest.h"
#include "game.h"
#include "card.h"
#include "player.h"
#include <iostream>

TEST(CardTest, RarityToString)
{
    EXPECT_EQ(rarityToString(Rarity::ORDINARY), "Ordinary");
    EXPECT_EQ(rarityToString(Rarity::RARE), "Rare");
    EXPECT_EQ(rarityToString(Rarity::EPIC), "Epic");
    EXPECT_EQ(rarityToString(Rarity::LEGENDARY), "Legendary");
}

TEST(CardTest, CardTypeToString)
{
    EXPECT_EQ(cardTypeToString(CardType::NINJA), "Ninja");
    EXPECT_EQ(cardTypeToString(CardType::WIZARD), "Wizard");
    EXPECT_EQ(cardTypeToString(CardType::ARCHER), "Archer");
    EXPECT_EQ(cardTypeToString(CardType::KNIGHT), "Knight");
    EXPECT_EQ(cardTypeToString(CardType::BISHOP), "Bishop");
}

TEST(CardTest, SuperPowerToString)
{
    EXPECT_EQ(superPowerToString(SuperPower::NONE), "None");
    EXPECT_EQ(superPowerToString(SuperPower::FIRE), "Fire");
    EXPECT_EQ(superPowerToString(SuperPower::FREEZE), "Freeze");
    EXPECT_EQ(superPowerToString(SuperPower::STORM), "Storm");
}

TEST(CardTest, CardCreation1)
{
    Card card(Rarity::RARE, CardType::WIZARD, 100, 20);
    EXPECT_EQ(card.rarity, Rarity::RARE);
    EXPECT_EQ(card.type, CardType::WIZARD);
    EXPECT_EQ(card.health, 100);
    EXPECT_EQ(card.strength, 20);
    EXPECT_EQ(card.mana, 0);
}

TEST(CardTest, CardCreation2) {
    Card card(Rarity::EPIC, CardType::ARCHER, 50, 30);
    EXPECT_EQ(card.rarity, Rarity::EPIC);
    EXPECT_EQ(card.type, CardType::ARCHER);
    EXPECT_EQ(card.health, 50);
    EXPECT_EQ(card.strength, 30);
    EXPECT_EQ(card.mana, 0);
}

TEST(CardTest, CardEquality)
{
    Card card1(Rarity::RARE, CardType::WIZARD, 100, 20);
    Card card2(Rarity::RARE, CardType::WIZARD, 120, 25);
    Card card3(Rarity::EPIC, CardType::WIZARD, 100, 20);
    EXPECT_TRUE(card1 == card2);
    EXPECT_FALSE(card1 == card3);
}

TEST(CardTest, CardToString)
{
    Card card(Rarity::EPIC, CardType::KNIGHT, 150, 30);
    std::string expected = "Epic Knight (150 HP, 30 POWER)";
    EXPECT_EQ(card.toString(), expected);
}

TEST(CardTest, UpgradeRarity)
{
    EXPECT_EQ(upgradeRarity(Rarity::ORDINARY), Rarity::RARE);
    EXPECT_EQ(upgradeRarity(Rarity::RARE), Rarity::EPIC);
    EXPECT_EQ(upgradeRarity(Rarity::EPIC), Rarity::LEGENDARY);
    EXPECT_EQ(upgradeRarity(Rarity::LEGENDARY), Rarity::LEGENDARY);
}

TEST(PlayerTest, PlayerCreation)
{
    Player player("TestPlayer");
    EXPECT_EQ(player.getName(), "TestPlayer");
    EXPECT_EQ(player.getScore(), 0);
    EXPECT_EQ(player.getMana(), 0);
    EXPECT_EQ(player.hand.size(), 0);
}

TEST(PlayerTest, GetSetScore)
{
    Player player("TestPlayer");
    player.addScore(10);
    EXPECT_EQ(player.getScore(), 10);
    player.addScore(5);
    EXPECT_EQ(player.getScore(), 15);
}

TEST(PlayerTest, DrawCard)
{
    Player player("TestPlayer");
    Card card(Rarity::RARE, CardType::WIZARD, 100, 20);
    player.drawCard(card);
    EXPECT_EQ(player.hand.size(), 1);
    EXPECT_EQ(player.hand[0].rarity, Rarity::RARE);
    EXPECT_EQ(player.hand[0].type, CardType::WIZARD);

}

TEST(PlayerTest, PlayCard)
{
    Player player1("Player1");
    Card card(Rarity::RARE, CardType::WIZARD, 100, 20);
    player1.drawCard(card);
    EXPECT_EQ(player1.hand.size(), 1);
}
TEST(PlayerTest, AttackCards)
{
    Player player1("Player1");
    Player player2("Player2");
    Card card1(Rarity::RARE, CardType::WIZARD, 110, 30);
    Card card2(Rarity::EPIC, CardType::ARCHER, 100, 20);
    player1.drawCard(card1);
    player2.drawCard(card2);
    player1.playCard(0, player2, 0);
    EXPECT_EQ(player2.hand[0].rarity, Rarity::EPIC);
    EXPECT_EQ(player2.hand[0].type, CardType::ARCHER);
    EXPECT_EQ(player2.hand[0].health, 70);
    EXPECT_EQ(player2.hand[0].strength, 20);
    EXPECT_EQ(player2.hand.size(), 1);
}

TEST(PlayerTest, DestructionCards)
{
    Player player1("Player1");
    Player player2("Player2");
    Card card1(Rarity::RARE, CardType::WIZARD, 110, 30);
    Card card2(Rarity::EPIC, CardType::ARCHER, 20, 20);
    player1.drawCard(card1);
    player2.drawCard(card2);
    player1.playCard(0, player2, 0);
    EXPECT_EQ(player2.hand.size(), 0);
}

TEST(PlayerTest, CanMergeCards)
{
    Player player("TestPlayer");
    Card card1(Rarity::RARE, CardType::WIZARD, 150, 30);
    Card card2(Rarity::RARE, CardType::WIZARD, 100, 20);
    player.drawCard(card1);
    player.drawCard(card2);
    EXPECT_TRUE(player.canMergeCards(0, 1));
}

TEST(PlayerTest, CantMergeCards)
{
    Player player("TestPlayer");
    Card card1(Rarity::EPIC, CardType::WIZARD, 150, 30);
    Card card2(Rarity::RARE, CardType::WIZARD, 100, 20);
    player.drawCard(card1);
    player.drawCard(card2);
    EXPECT_FALSE(player.canMergeCards(0, 1));
}

TEST(PlayerTest, MergeCards)
{
    Player player("TestPlayer");
    Card card1(Rarity::EPIC, CardType::ARCHER, 100, 20);
    Card card2(Rarity::EPIC, CardType::ARCHER, 100, 20);
    player.drawCard(card1);
    player.drawCard(card2);
    player.mergeCards(0, 1);
    EXPECT_EQ(player.hand[0].rarity, Rarity::LEGENDARY); 
    EXPECT_EQ(player.hand[0].type, CardType::ARCHER); 
    EXPECT_EQ(player.hand.size(), 1);

}

TEST(PlayerTest, UseSuperPower)
{
    Player player1("Player1");
    Card card1(Rarity::EPIC, CardType::ARCHER, 100, 20);
    player1.currentSuperPower = SuperPower::FIRE;
}

TEST(PlayerTest, GetSetScore1)
{
    Player player("TestPlayer");
    player.addScore(10);
    EXPECT_EQ(player.getScore(), 10);
    player.addScore(5);
    EXPECT_EQ(player.getScore(), 15);
}

TEST(PlayerTest, GetSetName)
{
    Player player("TestPlayer");
    EXPECT_EQ(player.getName(), "TestPlayer");
}

TEST(PlayerTest, GetSetMana)
{
    Player player("TestPlayer");
    player.addMana(5);
    EXPECT_EQ(player.getMana(), 5);
    player.resetMana();
    EXPECT_EQ(player.getMana(), 0);
}

TEST(PlayerTest, CanUseSuperPower)
{
    Player player("TestPlayer");
    player.currentSuperPower = SuperPower::FIRE;
    EXPECT_FALSE(player.canUseSuperPower());
    player.addMana(5);
    EXPECT_TRUE(player.canUseSuperPower());
}

TEST(GameTest, DealInitialHands)
{
    Game game;
    Player player1("Player1");
    Player player2("Player2");
    game.dealInitialHands(player1, player2);
    EXPECT_EQ(player1.hand.size(), 7);
    EXPECT_EQ(player2.hand.size(), 7);
}

TEST(GameTest, GenerateRandomCard)
{
    std::srand(12312);
    Game game;
    Card card = game.generateRandomCard();
    EXPECT_TRUE(card.health > 0);
    EXPECT_TRUE(card.strength >= 0);
}

TEST(GameTest, GenerateRandomCardRarity)
{
    std::srand(54321);
    Game game;
    Card card = game.generateRandomCard();
    EXPECT_TRUE(static_cast<int>(card.rarity) >= 0 && static_cast<int>(card.rarity) <= 3);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

