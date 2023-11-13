#include "gtest/gtest.h"
#include "pokerHand.h"

TEST(PokerHandTest, PlayerTwoWins) {
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "2C 3H 4S 8C AH"), "Player Two Wins");
    EXPECT_EQ(bestPokerHand("3H 3D 2S 9H 9D", "3H 3D 3S 9H 9D"), "Player Two Wins");
}

TEST(PokerHandTest, PlayerOneWins) {
    EXPECT_EQ(bestPokerHand("2H 4S 4C 2D 4H", "2S 8S AS QS 3S"), "Player One Wins");
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "2C 3H 4S 8C KH"), "Player One Wins");
}

TEST(PokerHandTest, Tie) {
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "2C 3H 5D 9S KH"), "Tie");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
