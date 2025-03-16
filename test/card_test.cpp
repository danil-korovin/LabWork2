#include "gtest/gtest.h"
#include "card.h"

TEST(CardTest, CardCreation) {
    Card card(Rarity::RARE, CardType::WIZARD, 100, 20);
    ASSERT_EQ(card.rarity, Rarity::RARE);
    ASSERT_EQ(card.type, CardType::WIZARD);
    ASSERT_EQ(card.health, 100);
    ASSERT_EQ(card.strength, 20);
    ASSERT_EQ(card.mana, 0);
}

TEST(CardTest, RarityToString) {
    ASSERT_EQ(rarityToString(Rarity::LEGENDARY), "Legendary");
    ASSERT_EQ(rarityToString(Rarity::ORDINARY), "Ordinary");
}

TEST(CardTest, CardToString) {
    Card card(Rarity::EPIC, CardType::KNIGHT, 150, 30);
    ASSERT_EQ(card.toString(), "Epic Knight (150 HP, 30 STR)");
}

TEST(CardTest, CardEquality) {
    Card card1(Rarity::RARE, CardType::WIZARD, 100, 20);
    Card card2(Rarity::RARE, CardType::WIZARD, 120, 25); 
    Card card3(Rarity::EPIC, CardType::WIZARD, 100, 20);

    ASSERT_TRUE(card1 == card2); 
    ASSERT_FALSE(card1 == card3); 
}
