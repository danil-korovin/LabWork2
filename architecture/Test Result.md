# Result ot test
```
[==========] Running 25 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 8 tests from CardTest
[ RUN      ] CardTest.RarityToString
[       OK ] CardTest.RarityToString (0 ms)
[ RUN      ] CardTest.CardTypeToString
[       OK ] CardTest.CardTypeToString (0 ms)
[ RUN      ] CardTest.SuperPowerToString
[       OK ] CardTest.SuperPowerToString (0 ms)
[ RUN      ] CardTest.CardCreation1
[       OK ] CardTest.CardCreation1 (0 ms)
[ RUN      ] CardTest.CardCreation2
[       OK ] CardTest.CardCreation2 (0 ms)
[ RUN      ] CardTest.CardEquality
[       OK ] CardTest.CardEquality (0 ms)
[ RUN      ] CardTest.CardToString
[       OK ] CardTest.CardToString (0 ms)
[ RUN      ] CardTest.UpgradeRarity
[       OK ] CardTest.UpgradeRarity (0 ms)
[----------] 8 tests from CardTest (0 ms total)

[----------] 14 tests from PlayerTest
[ RUN      ] PlayerTest.PlayerCreation
[       OK ] PlayerTest.PlayerCreation (0 ms)
[ RUN      ] PlayerTest.GetSetScore
[       OK ] PlayerTest.GetSetScore (0 ms)
[ RUN      ] PlayerTest.DrawCard
[       OK ] PlayerTest.DrawCard (0 ms)
[ RUN      ] PlayerTest.PlayCard
[       OK ] PlayerTest.PlayCard (0 ms)
[ RUN      ] PlayerTest.AttackCards
Player1 using Rare Wizard (110 HP, 30 POWER) attacks Epic Archer (100 HP, 20 POWER)
Card Epic Archer (70 HP, 20 POWER) received 30 damage.
[       OK ] PlayerTest.AttackCards (0 ms)
[ RUN      ] PlayerTest.DestructionCards
Player1 using Rare Wizard (110 HP, 30 POWER) attacks Epic Archer (20 HP, 20 POWER)
Card Epic Archer (-10 HP, 20 POWER) received 30 damage.
Card Epic Archer (-10 HP, 20 POWER) is destroyed!
[       OK ] PlayerTest.DestructionCards (0 ms)
[ RUN      ] PlayerTest.CanMergeCards
[       OK ] PlayerTest.CanMergeCards (0 ms)
[ RUN      ] PlayerTest.CantMergeCards
[       OK ] PlayerTest.CantMergeCards (0 ms)
[ RUN      ] PlayerTest.MergeCards
TestPlayer combined cards!  New card: Legendary Archer (200 HP, 40 POWER)
[       OK ] PlayerTest.MergeCards (0 ms)
[ RUN      ] PlayerTest.UseSuperPower
[       OK ] PlayerTest.UseSuperPower (0 ms)
[ RUN      ] PlayerTest.GetSetScore1
[       OK ] PlayerTest.GetSetScore1 (0 ms)
[ RUN      ] PlayerTest.GetSetName
[       OK ] PlayerTest.GetSetName (0 ms)
[ RUN      ] PlayerTest.GetSetMana
[       OK ] PlayerTest.GetSetMana (0 ms)
[ RUN      ] PlayerTest.CanUseSuperPower
[       OK ] PlayerTest.CanUseSuperPower (0 ms)
[----------] 14 tests from PlayerTest (0 ms total)

[----------] 3 tests from GameTest
[ RUN      ] GameTest.DealInitialHands
[       OK ] GameTest.DealInitialHands (0 ms)
[ RUN      ] GameTest.GenerateRandomCard
[       OK ] GameTest.GenerateRandomCard (0 ms)
[ RUN      ] GameTest.GenerateRandomCardRarity
[       OK ] GameTest.GenerateRandomCardRarity (0 ms)
[----------] 3 tests from GameTest (0 ms total)

[----------] Global test environment tear-down
[==========] 25 tests from 3 test suites ran. (1 ms total)
[  PASSED  ] 25 tests.
```
