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

//**************************Mover tests********************************************
TEST_CASE("Speed cannot be less than or equal to zero"){
	
		auto position = make_shared<Position>(150,350);
		auto negative_speed = -10;
		CHECK_THROWS_AS(Mover(position,negative_speed),NegativeZeroSpeed);
		auto zero_speed = 0;
		CHECK_THROWS_AS(Mover(position,zero_speed),NegativeZeroSpeed);
}
TEST_CASE("Position attribute returns correct values"){

		auto position = make_shared<Position>(400,300);
		auto speed = 3;
		auto position_attribute = make_shared<Mover>(position,speed);
		auto x = 400;
		auto y = 300;
		
		auto[x_attribute,y_attribute] = position_attribute->position()->getPosition();

		CHECK(x == x_attribute);
		CHECK(y == y_attribute);
		CHECK_FALSE(x_attribute == y_attribute);
}

TEST_CASE("Position attribute changes accordingly when moving left"){
	
		auto position = make_shared<Position>(400,300);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::LEFT);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = 395;
		auto new_y = 300;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_x_pos == new_x_pos);
}

TEST_CASE("Cannot move left when x position is zero"){
		auto position = make_shared<Position>((Constants::PLAYER_WIDTH_/2),300);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::LEFT);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = Constants::PLAYER_WIDTH_/2;
		auto new_y = 300;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_x_pos != new_x_pos);		
}

TEST_CASE("Position attribute returns correct values after moving right"){
	
		auto position = make_shared<Position>(300,400);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::RIGHT);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = 305;
		auto new_y = 400;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_x_pos == new_x_pos);
}

TEST_CASE("Cannot move right when x = Display width"){
		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_-(Constants::PLAYER_WIDTH_/2),500);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::RIGHT);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = Constants::DISPLAY_WIDTH_-(Constants::PLAYER_WIDTH_/2);
		auto new_y = 500;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_x_pos != new_x_pos);		
}

TEST_CASE("Position attribute changes accordingly when moving up"){
		auto position = make_shared<Position>(300,400);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::UP);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = 300;
		auto new_y = 395;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_y_pos == new_y_pos);
}

TEST_CASE("Cannot move up at y = 0"){
		auto position = make_shared<Position>(300,Constants::PLAYER_HEIGHT_/2);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::UP);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = 300;
		auto new_y = Constants::PLAYER_HEIGHT_/2;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_y_pos != new_y_pos);
}

TEST_CASE("Position attributes changes accordingly when moving down"){
		auto position = make_shared<Position>(200,300);
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::DOWN);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = 200;
		auto new_y = 305;
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_y_pos == new_y_pos);		
}
TEST_CASE("Cannot move down when y = screen height"){
		auto position = make_shared<Position>(300,Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2));
		auto speed = 5;
		
		auto move_attribute = make_shared<Mover>(position,speed);
		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
		move_attribute->move(Direction::DOWN);
		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
		
		auto new_x = 300;
		auto new_y = Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2);
		CHECK(new_x == new_x_pos);
		CHECK(new_y == new_y_pos);
		CHECK_FALSE(old_y_pos != new_y_pos);	
}
//TEST_CASE("Mover's position cannot be outside screen borders"){
//		auto position = make_shared<Position>(-10,-50);
//		auto speed = 5;
//		CHECK_THROWS_AS(Mover(position,speed),NegativePosition);
//}






