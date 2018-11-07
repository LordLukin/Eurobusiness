#include <gtest/gtest.h>
#include "Board.hpp"
#include "Field.hpp"
#include <memory>

struct BoardTest : public ::testing::Test
{
    Board board;
};

TEST_F(BoardTest, check_if_factoryFields_made_Property_Madrit)
{
    std::shared_ptr<Field> madrit = board.factoryFields("Espania - Madrit");
    ASSERT_EQ("Madrit", madrit->getName());
}

TEST_F(BoardTest, check_if_factoryFields_made_Railway_West)
{
    std::shared_ptr<Field> railway = board.factoryFields("Koleje wschodnie");
    ASSERT_EQ("Koleje wschodnie", railway->getName());
}

TEST_F(BoardTest, check_if_factoryFields_made_OrdynaryCard)
{
    std::shared_ptr<Field> ordinaryCard = board.factoryFields("Start");
    ASSERT_EQ("Start", ordinaryCard->getName());
}

TEST_F(BoardTest, check_if_method_readFile_return_json_file)
{
    json j = board.readFile("../files/configData.json");
    ASSERT_EQ("Start", j["fields"]["0"]);
}

TEST_F(BoardTest, check_method_setCards_if_correct_set_blue_and_red_cards)
{
    json j = board.readFile("../files/configData.json");
    board.setCards(j);
    ASSERT_EQ("Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $", board.getRedCard());
    ASSERT_EQ("Płacisz na budowę szpitala 400 $.", board.getBlueCard());
}

TEST_F(BoardTest, check_method_setFieldToCards_if_correct_set_pointer_Cards_to_field)
{
    json j = board.readFile("../files/configData.json");
    board.setCards(j);
    board.setFieldToCards(j);
    ASSERT_EQ("Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $", std::dynamic_pointer_cast<Cards>(board.getField(7))->getOneCard(0));
    ASSERT_EQ("Płacisz na budowę szpitala 400 $.", std::dynamic_pointer_cast<Cards>(board.getField(2))->getOneCard(0));
}
