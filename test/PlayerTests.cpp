#include <gtest/gtest.h>
#include "Player.hpp"

struct PlayerTests : public ::testing::Test
{
    Player player{"red"};
};

TEST_F(PlayerTests, check_if_player)
{
    ASSERT_EQ("red", player.getColor());
    ASSERT_EQ(3000,  player.amountOfMoney());
    ASSERT_TRUE(player.isStillInGame());
    ASSERT_EQ(0,player.getLocation());
    ASSERT_FALSE(player.ownsProperty());
}