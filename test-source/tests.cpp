#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source/Position.h"
#include "../game-source/Mover.h"

#include <memory>
using namespace std;

//***********************Position tests*******************************
TEST_CASE("Position cannot be less that zero"){
	
	CHECK_THROWS_AS(Position(-150,350),NegativePosition);
	CHECK_THROWS_AS(Position(150,-350),NegativePosition);
	CHECK_THROWS_AS(Position(-150,-350),NegativePosition);
}

TEST_CASE("Position cannot be greater than screen dimensions"){
	
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_+5,Constants::DISPLAY_HEIGHT_),OutOfBounds);
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_,Constants::DISPLAY_HEIGHT_+10),OutOfBounds);
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_+1,Constants::DISPLAY_HEIGHT_+1),OutOfBounds);

}

TEST_CASE("Getter function returns expected values"){
	
	Position position(800,600);	
	auto[x_position,y_position] = position.getPosition();
	auto x = 800;
	auto y = 600;
	CHECK(x == x_position);
	CHECK(y == y_position);
	CHECK_FALSE(x == y_position);
	CHECK_FALSE(y == x_position);
	
}

TEST_CASE("Setter function effective"){
	
	Position set_position(550,550);
	auto[x_pos,y_pos] = set_position.getPosition();
	auto x = 550;
	auto y = 550;
	CHECK(x == x_pos);
	CHECK(y == y_pos);
	
	auto new_x = 800;
	auto new_y = 600;
	set_position.setPosition(new_x,new_y);
	auto[newXPosition,newYPosition] = set_position.getPosition();
	CHECK(new_x == newXPosition);
	CHECK(new_y == newYPosition);
}

TEST_CASE("Default position is origin"){
		Position origin;
		
		auto[x_pos,y_pos] = origin.getPosition();
		auto x = 0;
		auto y = 0;
		CHECK(x == x_pos);
		CHECK(y == y_pos);
}
//*************************end of Position tests(5 tests)*********************************








