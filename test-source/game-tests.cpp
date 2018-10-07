#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source/Position.h"
#include "../game-source/Entity.h"
#include "../game-source/Mover.h"
#include "../game-source/Laser.h"
#include "../game-source/Player.h"
//#include "../game-source-code/Constants.h"
#include "../game-source/Segment.h"
//#include "../game-source-code/Enums.h"
#include "../game-source/Centipede.h"
#include "../game-source/Mushroom.h"
#include "../game-source/Field.h"
#include "../game-source/Box.h"
#include "../game-source/CollisionDetection.h"
#include "../game-source/CollisionReaction.h"



//***********************Position tests*******************************
TEST_CASE("Position cannot be less that zero"){
	
	CHECK_THROWS_AS(Position(-150,350),NegativePosition);
	CHECK_THROWS_AS(Position(150,-350),NegativePosition);
	CHECK_THROWS_AS(Position(-150,-350),NegativePosition);
}//1-3assert

TEST_CASE("Position cannot be greater than screen dimensions"){
	
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_+5,Constants::DISPLAY_HEIGHT_),OutOfBounds);
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_,Constants::DISPLAY_HEIGHT_+10),OutOfBounds);
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_+1,Constants::DISPLAY_HEIGHT_+1),OutOfBounds);

}//2-6assert
TEST_CASE("x position getter function returns expected value"){
	auto x = 800.0f;
	auto y = 600.0f;
	Position position(x,y);
	CHECK(doctest::Approx(x) == position.getXPosition());
	CHECK_FALSE(doctest::Approx(y) == position.getXPosition());
}//3-8assert
TEST_CASE("y position getter function returns expected value"){
	auto x = 250.0f;
	auto y = 350.0f;
	Position position(x,y);
	CHECK(doctest::Approx(y) == position.getYPosition());
	CHECK_FALSE(doctest::Approx(x) == position.getYPosition());
}//4-10assert
TEST_CASE("XY position getter function returns expected values"){
	
	auto x = 800.0f;
	auto y = 600.0f;
	Position position(x,y);	
	auto[x_position,y_position] = position.getXYPosition();
	CHECK(doctest::Approx(x) == x_position);
	CHECK(doctest::Approx(y) == y_position);
	CHECK_FALSE(doctest::Approx(x) == y_position);
	CHECK_FALSE(doctest::Approx(y) == x_position);
	
}//5-14assert
TEST_CASE("x position setter function behaves expectedly"){
	auto x = 800.0f;
	auto y = 600.0f;
	Position position(x,y);
	auto new_x = 450.0f;
	position.setXPosition(new_x);
	CHECK(doctest::Approx(new_x) == position.getXPosition());
	CHECK_FALSE(doctest::Approx(x) == position.getXPosition());
}//6-16assert
TEST_CASE("y position setter function behaves expectedly"){
	auto x = 450.0f;
	auto y = 350.0f;
	Position position(x,y);
	auto new_y = 250.0f;
	position.setYPosition(new_y);
	CHECK(doctest::Approx(new_y) == position.getYPosition());
	CHECK_FALSE(doctest::Approx(y) == position.getYPosition());
}//7-18assert
//
TEST_CASE("XY position Setter function effective"){
	auto x = 550.0f;
	auto y = 550.0f;
	Position _position(x,y);
	auto[oldXPosition,oldYPosition] = _position.getXYPosition();
	auto new_x = 800.0f;
	auto new_y = 600.0f;
	_position.setXYPosition(new_x,new_y);
	auto[newXPosition,newYPosition] = _position.getXYPosition();
	
	CHECK(doctest::Approx(new_x) == newXPosition);
	CHECK(doctest::Approx(new_y) == newYPosition);
	CHECK_FALSE(doctest::Approx(oldXPosition) == newXPosition);
	CHECK_FALSE(doctest::Approx(oldYPosition) == newYPosition);
}//8-22assert
//
TEST_CASE("Default position is origin"){
		Position origin;
		
		auto[x_pos,y_pos] = origin.getXYPosition();
		auto x = 0.0f;
		auto y = 0.0f;
		CHECK(doctest::Approx(x) == x_pos);
		CHECK(doctest::Approx(y) == y_pos);
}//9-24assert

//*************************end of Position tests(9 tests)**************************

//*************************Entity Tests********************************************
TEST_CASE("Entity is not constructed with an invalid position"){
	//exceptions thrown in Position's constructor
	CHECK_THROWS(Entity(-1.0,-1.0,EntityID::PLAYER));
	CHECK_THROWS(Entity(Constants::DISPLAY_WIDTH_+1.0,Constants::DISPLAY_WIDTH_+1.0,EntityID::PLAYER));
}//10-26-assert
TEST_CASE("Entity returns valid position"){
	
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	
	auto entity = make_shared<Entity>(x,y,id);
	CHECK(doctest::Approx(x) == entity->position()->getXPosition());
	CHECK_FALSE(doctest::Approx(y) == entity->position()->getXPosition());
	CHECK(doctest::Approx(y) == entity->position()->getYPosition());
	CHECK_FALSE(doctest::Approx(x) == entity->position()->getYPosition());
	
	auto[entity_x,entity_y] = entity->position()->getXYPosition();
	CHECK(doctest::Approx(entity_x) == x);
	CHECK_FALSE(doctest::Approx(entity_x) == y);
	CHECK(doctest::Approx(entity_y) == y);
	CHECK_FALSE(doctest::Approx(entity_y) == x);
	
}//11-28assert
//
TEST_CASE("Entity can effectively set position"){
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	auto entity = make_shared<Entity>(x,y,id);
	auto[old_entity_x,old_entity_y] = entity->position()->getXYPosition();
	auto new_x = 250.0f;
	auto new_y = 300.0f;
	entity->position()->setXYPosition(new_x,new_y);
	auto[new_entity_x,new_entity_y] = entity->position()->getXYPosition();
	
	CHECK(doctest::Approx(new_x) == entity->position()->getXPosition());
	CHECK(doctest::Approx(new_y) == entity->position()->getYPosition());
	CHECK_FALSE(doctest::Approx(new_entity_x) == old_entity_x);
	CHECK_FALSE(doctest::Approx(new_entity_y) == old_entity_y);
}//11-32assert
//
TEST_CASE("Entity live state is true upon construction"){
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	auto entity = make_shared<Entity>(x,y,id);
	CHECK(entity->isLive());
	CHECK_FALSE(!entity->isLive());
}//12-34assert
//
TEST_CASE("Entity can be destroyed"){
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	auto entity = make_shared<Entity>(x,y,id);
	entity->destroy();
	CHECK(!entity->isLive());
	CHECK_FALSE(entity->isLive());
}//13-35assert
//
TEST_CASE("Correct Entity id is returned"){
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	auto entity = make_shared<Entity>(x,y,id);
	
	CHECK(id == entity->getEntityID());
	CHECK_FALSE(EntityID::SEGMENT == entity->getEntityID());
}//14-37assert
//*********************************************************************************
//***************************Laser Tests*******************************************
TEST_CASE("Laser cannot have a speed other than a set Laser speed"){
	
	CHECK_THROWS_AS(Laser(50,50,EntityID::LASER,Constants::PLAYER_SPEED_),IncorrectLaserSpeed);
	CHECK_THROWS_AS(Laser(100,250,EntityID::LASER,10.0),IncorrectLaserSpeed);
	
}//15-39assert
TEST_CASE("Cannot construct A Laser with a wrong Entity ID"){
		CHECK_THROWS_AS(Laser(250,550,EntityID::PLAYER,4.0),IncorrectLaserEntityID);
		CHECK_THROWS_AS(Laser(400,250,EntityID::MUSHROOM,4.0),IncorrectLaserEntityID);
		CHECK_THROWS_AS(Laser(400,250,EntityID::SEGMENT,4.0),IncorrectLaserEntityID);
}//16-42ASSERT
//
TEST_CASE("Valid laser position is returned"){
	auto x = 250.0f;
	auto y = 330.0f;
	auto id = EntityID::LASER;
	auto speed = 4.0f;
	Laser laser(x,y,id,speed);
	auto[returned_x,returned_y] = laser.entityAttribute()->position()->getXYPosition();
	CHECK(doctest::Approx(x) == returned_x);
	CHECK_FALSE(doctest::Approx(x) == returned_y);
	CHECK(doctest::Approx(y) == returned_y);
	CHECK_FALSE(doctest::Approx(y) == returned_x);
}
TEST_CASE("Laser movement can be updated"){
	auto x = 250.0f;
	auto y = 330.0f;
	auto id = EntityID::LASER;
	auto speed = 4.0f;
	Laser laser(x,y,id,speed);
	auto old_y = laser.entityAttribute()->position()->getYPosition();
	laser.updatePosition();
	auto new_y = laser.entityAttribute()->position()->getYPosition(); 
	CHECK(doctest::Approx(new_y) == old_y-speed);
	CHECK_FALSE(doctest::Approx(new_y) == old_y);
}//17-43assert
//
TEST_CASE("Laser's live state changes when it goes out of screen bound"){
	auto x = 250.0f;
	auto y = 10.0f;
	auto id = EntityID::LASER;
	auto speed = 4.0f;
	Laser laser(x,y,id,speed);
	CHECK(laser.entityAttribute()->isLive());
	laser.updatePosition();
	CHECK_FALSE(laser.entityAttribute()->isLive());
}//19-47assert
//
TEST_CASE("Laser only moves vertically upwards"){
	auto x = 250.0f;
	auto y = 350.0f;
	auto id = EntityID::LASER;
	auto speed = 4.0f;
	Laser laser(x,y,id,speed);
	auto[old_x,old_y] = laser.entityAttribute()->position()->getXYPosition();
	laser.updatePosition();
	auto[new_x,new_y] = laser.entityAttribute()->position()->getXYPosition();
	CHECK(doctest::Approx(old_x) == new_x);
	CHECK_FALSE(doctest::Approx(new_x) == old_x - speed);
	CHECK_FALSE(doctest::Approx(new_x) == old_x + speed);
	CHECK_FALSE(doctest::Approx(new_y) == old_y + speed);
}//20-49assert
//*********************************************************************************
//**************************Player Tests*******************************************
TEST_CASE("Player is constructed with a correct EntityID"){
	
	CHECK_THROWS_AS(Player(250,450,EntityID::SEGMENT,Constants::PLAYER_SPEED_),IncorrectPlayerEntityID);
	CHECK_THROWS_AS(Player(250,450,EntityID::LASER,Constants::PLAYER_SPEED_),IncorrectPlayerEntityID);
	CHECK_THROWS_AS(Player(250,450,EntityID::MUSHROOM,Constants::PLAYER_SPEED_),IncorrectPlayerEntityID);
	
}//21-52assert

TEST_CASE("Player is constructed with a correct speed"){
	
	CHECK_THROWS_AS(Player(250,450,EntityID::MUSHROOM,Constants::LASER_SPEED_),IncorrectPlayerSpeed);
	CHECK_THROWS_AS(Player(250,450,EntityID::MUSHROOM,6.0),IncorrectPlayerSpeed);
	CHECK_THROWS_AS(Player(250,450,EntityID::MUSHROOM,4.5),IncorrectPlayerSpeed);
	
}//22-55assert
//
TEST_CASE("Player constructed with a valid Position"){
	CHECK_THROWS(Player(-1.0,-1.0,EntityID::PLAYER,Constants::PLAYER_SPEED_));
	CHECK_THROWS(Player(801.0,601.0,EntityID::PLAYER,Constants::PLAYER_SPEED_));
}
TEST_CASE("Player cannot be constructed above its movement region"){
	CHECK_THROWS_AS(Player(50,Constants::PLAYER_VERTICAL_LIMIT-1.0,EntityID::PLAYER,Constants::PLAYER_SPEED_),IncorrectPlayerPosition);
}
//
TEST_CASE("valid player position is returned"){
	auto x = 450.0f;
	auto y = 550.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto[returned_x,returned_y] = player.entityAttribute()->position()->getXYPosition();
	CHECK(doctest::Approx(x) == returned_x);
	CHECK_FALSE(doctest::Approx(x) == returned_y);
	CHECK(doctest::Approx(y) == returned_y);
	CHECK_FALSE(doctest::Approx(y) == returned_x);
}

TEST_CASE("Player can move right"){
	auto x = 450.0f;
	auto y = 550.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_x = player.entityAttribute()->position()->getXPosition();
	player.move(Direction::RIGHT);
	auto new_x = player.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x+speed);
	CHECK_FALSE(doctest::Approx(new_x) == old_x);
	
}//23-56aseert
TEST_CASE("Player cannot move right when at rightmost border of the screen"){
	auto x = 784.0f;
	auto y = 550.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_x = player.entityAttribute()->position()->getXPosition();
	player.move(Direction::RIGHT);
	auto new_x = player.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x);
	CHECK_FALSE(doctest::Approx(new_x) == old_x+speed);
		
}//24-58assert
TEST_CASE("Player can move left"){
	auto x = 784.0f;
	auto y = 550.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_x = player.entityAttribute()->position()->getXPosition();
	player.move(Direction::LEFT);
	auto new_x = player.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x-speed);
	CHECK_FALSE(doctest::Approx(new_x) == old_x);	
}//25-60assert
//
TEST_CASE("Player cannot move left when at leftmost screen border"){
	auto x = 4.0f;
	auto y = 550.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_x = player.entityAttribute()->position()->getXPosition();
	player.move(Direction::LEFT);
	auto new_x = player.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x);
	CHECK_FALSE(doctest::Approx(new_x) == old_x-speed);	
}//26-62assert
//
TEST_CASE("Player can move up"){
	auto x = 250.0f;
	auto y = 550.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_y = player.entityAttribute()->position()->getYPosition();
	player.move(Direction::UP);
	auto new_y = player.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y-speed);
	CHECK_FALSE(doctest::Approx(new_y) == old_y);		
}//27-64assert
//
TEST_CASE("Player cannot move up beyond a set border"){
	auto x = 250.0f;
	auto y = 450.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_y = player.entityAttribute()->position()->getYPosition();
	player.move(Direction::UP);
	auto new_y = player.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y);
	CHECK_FALSE(doctest::Approx(new_y) == old_y-speed);	
	
}//28-66assert
//
TEST_CASE("Player can move down"){
	auto x = 250.0f;
	auto y = 450.0f;	//set limit
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_y = player.entityAttribute()->position()->getYPosition();
	player.move(Direction::DOWN);
	auto new_y = player.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y+speed);
	CHECK_FALSE(doctest::Approx(new_y) == old_y);		
}//29-68assert
//
TEST_CASE("Player cannot move down when at bottom of the screen"){
	auto x = 250.0f;
	auto y = 584.0f;	//set limit
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_y = player.entityAttribute()->position()->getYPosition();
	player.move(Direction::DOWN);
	auto new_y = player.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y);
	CHECK_FALSE(doctest::Approx(new_y) == old_y+speed);		
}//30-70assert
//
TEST_CASE("There are no lasers if player does not shoot"){
	auto x = 50.0f;
	auto y = 550.0f;
	
	Player player(x,y,EntityID::PLAYER,Constants::PLAYER_SPEED_);
	auto start_lasers_iterator = begin(player.getLasers());
	auto end_lasers_iterator = end(player.getLasers());
	
	CHECK(start_lasers_iterator == end_lasers_iterator);
}
//
TEST_CASE("A laser gets created when a player shoots"){
	auto x = 50.0f;
	auto y = 550.0f;
	
	Player player(x,y,EntityID::PLAYER,Constants::PLAYER_SPEED_);
	player.shoot();
	auto _lasers_iterator = begin(player.getLasers());

	
	auto number_of_lasers = 1;
	auto count = 0;
	while(_lasers_iterator != end(player.getLasers())){
		++_lasers_iterator;
		++count;
	}
	
	CHECK(number_of_lasers == count);
	CHECK_FALSE(number_of_lasers == 0);
	
}
//
TEST_CASE("Laser gets constructed with a valid position"){
	auto x = 50.0f;
	auto y = 550.0f;
	
	Player player(x,y,EntityID::PLAYER,Constants::PLAYER_SPEED_);
	//Position would throw an exception for invalid position
	CHECK_NOTHROW(player.shoot());
}
TEST_CASE("The number of lasers created corresponds to the number of times a player shoots"){
	auto x = 50.0f;
	auto y = 550.0f;
	
	Player player(x,y,EntityID::PLAYER,Constants::PLAYER_SPEED_);

	player.shoot();
	player.shoot();
	player.shoot();
	
	auto lasers_counter = begin(player.getLasers());
	auto number_of_lasers = 3;
	auto laserCounter = 0;
	
	while(lasers_counter != end(player.getLasers())){
		++lasers_counter;
		++laserCounter;
	}
	
	CHECK(number_of_lasers == laserCounter);
	auto single_shot = 1;
	CHECK_FALSE(number_of_lasers == single_shot);
	
}
//
TEST_CASE("A Shot laser's position can be updated"){
	
	auto x = 50.0f;
	auto y = 550.0f;
	
	Player player(x,y,EntityID::PLAYER,Constants::PLAYER_SPEED_);
	player.shoot();
	auto laser_iterator = begin(player.getLasers());
	auto laser_x_i = (*laser_iterator)->entityAttribute()->position()->getYPosition();
	player.updateLasers();
	auto laser_x_f = (*laser_iterator)->entityAttribute()->position()->getYPosition();
	
	CHECK(doctest::Approx(laser_x_f) == laser_x_i - Constants::LASER_SPEED_);
	CHECK_FALSE(doctest::Approx(laser_x_f) == laser_x_i);
}
//*************************************************************************
//**************************Mushroom Tests**********************************
TEST_CASE("Mushroom is constructed with a correct EntityID"){
	
	CHECK_THROWS_AS(Mushroom(250,450,EntityID::SEGMENT),IncorrectMushroomEntityID);
	CHECK_THROWS_AS(Mushroom(250,450,EntityID::LASER),IncorrectMushroomEntityID);
	CHECK_THROWS_AS(Mushroom(250,450,EntityID::PLAYER),IncorrectMushroomEntityID);
	
}//21-52assert
TEST_CASE("Mushroom cannot be constructed with an invalid position"){
	
	CHECK_THROWS(Mushroom(-1.0,-1.0,EntityID::MUSHROOM));
	CHECK_THROWS(Mushroom(801.0,601.0,EntityID::MUSHROOM));
}
TEST_CASE("valid Mushroom position is returned"){
	auto x = 205.0f;
	auto y = 150.0f;
	Mushroom mushroom(x,y,EntityID::MUSHROOM);
	auto[returned_x,returned_y] = mushroom.entityAttribute()->position()->getXYPosition();
	CHECK(doctest::Approx(x) == returned_x);
	CHECK_FALSE(doctest::Approx(x) == returned_y);
	CHECK(doctest::Approx(y) == returned_y);
	CHECK_FALSE(doctest::Approx(y) == returned_x);
}
TEST_CASE("Mushroom's live state changes after being weakened four times"){
	auto mushroom_x_position = 320.0f;
	auto mushroom_y_position = 250.0f;
	auto mushroom_entity = EntityID::MUSHROOM;
	auto mushroom = make_shared<Mushroom>(mushroom_x_position,mushroom_y_position,mushroom_entity);
	
	mushroom->weaken();
	mushroom->weaken();
	mushroom->weaken();
	mushroom->weaken();
	
	CHECK_FALSE(mushroom->entityAttribute()->isLive());
	
}//31-71assert
//
TEST_CASE("Mushroom's live state remains unchanged if hit less than four times"){
	auto mushroom_x_position = 320.0f;
	auto mushroom_y_position = 250.0f;
	auto mushroom_entity = EntityID::MUSHROOM;
	auto mushroom = make_shared<Mushroom>(mushroom_x_position,mushroom_y_position,mushroom_entity);

	mushroom->weaken();
	mushroom->weaken();
	mushroom->weaken();
	
	auto dead = false;
	auto mushroom_state = mushroom->entityAttribute()->isLive();
	CHECK_FALSE(mushroom_state == dead);
}//32-72assert
//********************************************************************************
//***************************Field Tests*****************************************
TEST_CASE("Number of mushrooms generated by Field are greater than zero"){
	
	CHECK_THROWS_AS(Field(-1),InvalidFieldSize);
	CHECK_THROWS_AS(Field(0),InvalidFieldSize);	
}
//
TEST_CASE("Field generates mushrooms in valid positions"){
	
	//exception in Position would throw for invalid positions.
	CHECK_NOTHROW(Field(10));
	
}
TEST_CASE("Correct number of mushrooms is generated"){
	auto fieldSize = 10;
	Field field(fieldSize);
	auto mush_iterator = begin(field.getMushrooms());
	
	auto number_of_mushrooms = 0;
	
	while(mush_iterator != end(field.getMushrooms())){
		++mush_iterator;
		++number_of_mushrooms;
	}
	
	CHECK(number_of_mushrooms == fieldSize);
	auto invalidFieldSize = 35;
	CHECK_FALSE(number_of_mushrooms == invalidFieldSize);
}
//
TEST_CASE("Generated mushroom position is a multiple of four"){
	auto fieldSize = 1;
	Field field(fieldSize);
	auto mush_iterator = begin(field.getMushrooms());
	auto[mush_x,mush_y] = (*mush_iterator)->entityAttribute()->position()->getXYPosition();
	auto multiple = 4;
	
	CHECK(static_cast<int>(mush_x) % multiple == 0);
	CHECK(static_cast<int>(mush_y) % multiple == 0);
	
}
TEST_CASE("Mushrooms not generated at the top of the screen"){
	auto fieldSize = 35;
	Field field(fieldSize);
	auto mush_iterator = begin(field.getMushrooms());
	while(mush_iterator != end(field.getMushrooms())){
		auto y = (*mush_iterator)->entityAttribute()->position()->getYPosition();
		CHECK_GT(y,0.0);
		++mush_iterator;
	}
}
TEST_CASE("field creates a mushroom whenever instructed to do so"){
	auto fieldSize = 1;
	Field field(fieldSize);
	auto mush_x = 4.0f;
	auto mush_y = 32.0f;
	field.createMushroom(mush_x,mush_y);
	auto mush_iterator = begin(field.getMushrooms());
	auto number_of_mushrooms = 0;
	while(mush_iterator != end(field.getMushrooms())){
		++mush_iterator;
		++number_of_mushrooms;
	}
	auto newFieldSize = 2;
	CHECK(number_of_mushrooms == newFieldSize);
	CHECK_FALSE(number_of_mushrooms == fieldSize);
}

//***************************Segment Tests****************************************
TEST_CASE("Cannot construct Segment with an invalid EntityID"){
	
	CHECK_THROWS_AS(Segment(50,50,EntityID::PLAYER,Constants::SEGMENT_SPEED_),InvalidSegmentEntityID);
	CHECK_THROWS_AS(Segment(50,50,EntityID::LASER,Constants::SEGMENT_SPEED_),InvalidSegmentEntityID);
	CHECK_THROWS_AS(Segment(50,50,EntityID::MUSHROOM,Constants::SEGMENT_SPEED_),InvalidSegmentEntityID);
	
}//33-75assert
TEST_CASE("Cannot construct Segment with an invalid speed"){
	CHECK_THROWS_AS(Segment(50,50,EntityID::SEGMENT,Constants::PLAYER_SPEED_),InvalidSegmentSpeed);
	CHECK_THROWS_AS(Segment(50,50,EntityID::SEGMENT,5.0),InvalidSegmentSpeed);
	CHECK_THROWS_AS(Segment(50,50,EntityID::SEGMENT,6.5),InvalidSegmentSpeed);
	CHECK_THROWS_AS(Segment(50,50,EntityID::SEGMENT,3.9),InvalidSegmentSpeed);
}//34-79ASSERT
//
TEST_CASE("valid segment position is returned"){
	auto x = 250.0f;
	auto y = 350.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	Segment segment(x,y,id,speed);	
	
	auto[returned_x,returned_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CHECK(doctest::Approx(x) == returned_x);
	CHECK_FALSE(doctest::Approx(x) == returned_y);
	CHECK(doctest::Approx(y) == returned_y);
	CHECK_FALSE(doctest::Approx(y) == returned_x);
}
TEST_CASE("Segment can move right"){
	
	auto x = 250.0f;
	auto y = 350.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_x = segment.entityAttribute()->position()->getXPosition();
	segment.move(Direction::RIGHT);
	auto new_x = segment.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x+speed);
	CHECK_FALSE(doctest::Approx(old_x) == new_x);
	
}//35-81assert
//
TEST_CASE("Segment cannot move right when at rightmost screen border"){
	
	auto x = 784.0f;
	auto y = 350.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_x = segment.entityAttribute()->position()->getXPosition();
	segment.move(Direction::RIGHT);
	auto new_x = segment.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x);
	CHECK_FALSE(doctest::Approx(new_x) == old_x+speed);
	
}//36-83assert
//
TEST_CASE("Segment can move left"){
	
	auto x = 784.0f;
	auto y = 350.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_x = segment.entityAttribute()->position()->getXPosition();
	segment.move(Direction::LEFT);
	auto new_x = segment.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x-speed);
	CHECK_FALSE(doctest::Approx(new_x) == old_x);
	
}//37-85assert
//
TEST_CASE("Segment cannot move left when at leftmost screen border"){
	
	auto x = 4.0f;
	auto y = 350.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_x = segment.entityAttribute()->position()->getXPosition();
	segment.move(Direction::LEFT);
	auto new_x = segment.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x);
	CHECK_FALSE(doctest::Approx(new_x) == old_x-speed);
	
}//38-87assert
//
TEST_CASE("Segment can move up"){
	
	auto x = 550.0f;
	auto y = 550.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_y = segment.entityAttribute()->position()->getYPosition();
	segment.move(Direction::UP);
	auto new_y = segment.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y-4*speed);
	CHECK_FALSE(doctest::Approx(new_y) == old_y);
	
}//39-89assert
//
TEST_CASE("Segment cannot move up when at a set limit"){
	
	auto x = 4.0f;
	auto y = Constants::PLAYER_VERTICAL_LIMIT;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_x = segment.entityAttribute()->position()->getXPosition();
	segment.move(Direction::LEFT);
	auto new_x = segment.entityAttribute()->position()->getXPosition();
	CHECK(doctest::Approx(new_x) == old_x);
	CHECK_FALSE(doctest::Approx(new_x) == old_x-4*speed);
}//40-91assert
//
TEST_CASE("Segment can move down"){
	
	auto x = 550.0f;
	auto y = 550.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_y = segment.entityAttribute()->position()->getYPosition();
	segment.move(Direction::DOWN);
	auto new_y = segment.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y+4*speed);
	CHECK_FALSE(doctest::Approx(new_y) == old_y);
	
}//41-93-assert
//
TEST_CASE("Segment cannot move down when at a set limit"){
	
	auto x = 4.0f;
	auto y = 584.0f;
	auto id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	
	Segment segment(x,y,id,speed);
	auto old_y = segment.entityAttribute()->position()->getYPosition();
	segment.move(Direction::DOWN);
	auto new_y = segment.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y);
	CHECK_FALSE(doctest::Approx(new_y) == old_y-4*speed);
}//42-95assert
TEST_CASE("Segment faces left when instructed to face left"){
	auto x = 250.0f;
	auto y = 350.0f;
	Segment segment(x,y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	segment.faceLeft();
	CHECK(segment.isFacingLeft());
	CHECK_FALSE(segment.isFacingRight());
}
//
TEST_CASE("Segment faces right when instructed to face right"){
	auto x = 250.0f;
	auto y = 350.0f;
	Segment segment(x,y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	segment.faceRight();
	CHECK(segment.isFacingRight());
	CHECK_FALSE(segment.isFacingLeft());	
}
//
TEST_CASE("Segment faces down when instructed to face down"){
	auto x = 250.0f;
	auto y = 350.0f;
	Segment segment(x,y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	segment.faceDown();
	CHECK(segment.isFacingDown());
	CHECK_FALSE(segment.isFacingUp());
}
//
TEST_CASE("Segment faces up when instructed to face up"){
	auto x = 250.0f;
	auto y = 350.0f;
	Segment segment(x,y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	segment.faceUp();
	CHECK(segment.isFacingUp());
	CHECK_FALSE(segment.isFacingDown());	
}
//********************************************************************************
//************************************Box Tests***********************************
TEST_CASE("Valid Laser Box can be created"){
	auto laser_x = 50.0f;
	auto laser_y = 250.0f;
	auto laser_id = EntityID::LASER;
	auto speed = Constants::LASER_SPEED_;
	Laser laser(laser_x,laser_y,laser_id,speed);
	auto[x,y] = laser.entityAttribute()->position()->getXYPosition();
	Box box;
	auto[min_x,min_y,max_x,max_y] = box.getBox(x,y,laser.entityAttribute()->getEntityID());
	auto manual_min_x = x;
	auto manual_min_y = y+Constants::LASER_HEIGHT_;
	auto manual_max_x = x+Constants::LASER_WIDTH_;
	auto manual_max_y = y;
	
	
	CHECK(doctest::Approx(manual_min_x) == min_x);
	CHECK(doctest::Approx(manual_min_y) == min_y);
	CHECK(doctest::Approx(manual_max_x) == max_x);
	CHECK(doctest::Approx(manual_max_y) == max_y);
	
}//43-99assert
TEST_CASE("Valid Segment Box is created"){
	auto segment_x = 50.0f;
	auto segment_y = 250.0f;
	auto segment_id = EntityID::SEGMENT;
	auto speed = Constants::SEGMENT_SPEED_;
	Segment segment(segment_x,segment_y,segment_id,speed);
	auto[x,y] = segment.entityAttribute()->position()->getXYPosition();
	Box box;
	auto[min_x,min_y,max_x,max_y] = box.getBox(x,y,segment.entityAttribute()->getEntityID());
	auto manual_min_x = x;
	auto manual_min_y = y+Constants::SEGMENT_HEIGHT_;
	auto manual_max_x = x+Constants::SEGMENT_WIDTH_;
	auto manual_max_y = y;
	
	
	CHECK(doctest::Approx(manual_min_x) == min_x);
	CHECK(doctest::Approx(manual_min_y) == min_y);
	CHECK(doctest::Approx(manual_max_x) == max_x);
	CHECK(doctest::Approx(manual_max_y) == max_y);	
}//44-103assert
//
TEST_CASE("Valid Player Box can be created"){
	auto player_x = 50.0f;
	auto player_y = 550.0f;
	auto player_id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(player_x,player_y,player_id,speed);
	auto[x,y] = player.entityAttribute()->position()->getXYPosition();
	Box box;
	auto[min_x,min_y,max_x,max_y] = box.getBox(x,y,player.entityAttribute()->getEntityID());
	auto manual_min_x = x;
	auto manual_min_y = y+Constants::PLAYER_HEIGHT_;
	auto manual_max_x = x+Constants::PLAYER_WIDTH_;
	auto manual_max_y = y;
	
	
	CHECK(doctest::Approx(manual_min_x) == min_x);
	CHECK(doctest::Approx(manual_min_y) == min_y);
	CHECK(doctest::Approx(manual_max_x) == max_x);
	CHECK(doctest::Approx(manual_max_y) == max_y);
	
}//45-107assert
//
TEST_CASE("Valid Mushroom Box can be created"){
	auto mushroom_x = 50.0f;
	auto mushroom_y = 250.0f;
	auto mushroom_id = EntityID::MUSHROOM;
	Mushroom mushroom(mushroom_x,mushroom_y,mushroom_id);
	auto[x,y] = mushroom.entityAttribute()->position()->getXYPosition();
	Box box;
	auto[min_x,min_y,max_x,max_y] = box.getBox(x,y,mushroom.entityAttribute()->getEntityID());
	auto manual_min_x = x;
	auto manual_min_y = y+Constants::MUSHROOM_HEIGHT_;
	auto manual_max_x = x+Constants::MUSHROOM_WIDTH_;
	auto manual_max_y = y;
	
	
	CHECK(doctest::Approx(manual_min_x) == min_x);
	CHECK(doctest::Approx(manual_min_y) == min_y);
	CHECK(doctest::Approx(manual_max_x) == max_x);
	CHECK(doctest::Approx(manual_max_y) == max_y);
	
}//46-111assert
//*********************************************************************************
//***************************CollisionDetection Tests******************************
TEST_CASE("Only objects permitted to collide are tested for collision"){
	
	auto player = EntityID::PLAYER;
	auto laser = EntityID::LASER;
	auto mushroom = EntityID::MUSHROOM;
	auto segment = EntityID::SEGMENT;
	auto x = 250.0f;
	auto y = 150.0f;
	
		CHECK_THROWS_AS(CollisionDetection(x,y,player,x,y,laser),ObjectsNotCollidable);
		CHECK_THROWS_AS(CollisionDetection(x,y,player,x,y,mushroom),ObjectsNotCollidable);
		CHECK_THROWS_AS(CollisionDetection(x,y,player,x,y,player),ObjectsNotCollidable);
		CHECK_THROWS_AS(CollisionDetection(x,y,mushroom,x,y,mushroom),ObjectsNotCollidable);
		CHECK_THROWS_AS(CollisionDetection(x,y,laser,x,y,laser),ObjectsNotCollidable);
		CHECK_THROWS_AS(CollisionDetection(x,y,segment,x,y,segment),ObjectsNotCollidable);
}

//**************************Laser-Segment Collision Tests***************************
TEST_CASE("Top left laser corner collides with bottom left Segment corner"){
	auto laser_x = 250.0f;
	auto laser_y = 350.0f;
	auto laser_id = EntityID::LASER;
	auto laser_speed = Constants::LASER_SPEED_;
	Laser laser(laser_x,laser_y,laser_id,laser_speed);
	Box laser_box;
	auto[min_x,min_y,max_x,max_y] = laser_box.getBox(laser_x,laser_y,EntityID::LASER);
	auto seg_x = max_x;
	auto seg_y = max_y-Constants::SEGMENT_HEIGHT_;
	auto speed = Constants::SEGMENT_SPEED_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[seg_get_x,seg_get_y] = segment.entityAttribute()->position()->getXYPosition();
	auto[laser_get_x,laser_get_y] = laser.entityAttribute()->position()->getXYPosition();

	
	CollisionDetection collision_detector(seg_get_x,seg_get_y,EntityID::SEGMENT,
										laser_get_x,laser_get_y,EntityID::LASER);
										
	CHECK(collision_detector.collided());
}//47-112assert

TEST_CASE("Bottom right of Segment collides with top left of Laser"){
	auto seg_x = 150.0f;
	auto seg_y = 200.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	Box seg_box;
	auto[seg_min_x,seg_min_y,seg_max_x,seg_max_y] = seg_box.getBox(seg_x,seg_y,EntityID::SEGMENT);
	
	auto laser_x = seg_max_x;
	auto laser_y = seg_max_y+Constants::SEGMENT_HEIGHT_;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	
	auto[seg_get_x,seg_get_y] = segment.entityAttribute()->position()->getXYPosition();
	auto[laser_get_x,laser_get_y] = laser.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(seg_get_x,seg_get_y,EntityID::SEGMENT,
										laser_get_x,laser_get_y,EntityID::LASER);
										
	CHECK(collision_detector.collided());
	
}//48-113assert

TEST_CASE("Laser on bottom boundary of a Segment collides with it"){
	auto seg_x = 250.0f;
	auto seg_y = 350.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	Box seg_box;
	auto[seg_min_x,seg_min_y,seg_max_x,seg_max_y] = seg_box.getBox(seg_x,seg_y,EntityID::SEGMENT);
	
	auto laser_x = seg_min_x + Constants::SEGMENT_WIDTH_/2.0;
	auto laser_y = seg_min_y;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	
	auto[seg_get_x,seg_get_y] = segment.entityAttribute()->position()->getXYPosition();
	auto[laser_get_x,laser_get_y] = laser.entityAttribute()->position()->getXYPosition();

	CollisionDetection collision_detector(seg_get_x,seg_get_y,EntityID::SEGMENT,
										laser_get_x,laser_get_y,EntityID::LASER);

	CHECK(collision_detector.collided());	
	
}//49-114assert

TEST_CASE("Top right of segment collides with bottom left of laser"){
	auto seg_x = 450.0f;
	auto seg_y = 150.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	Box seg_box;
	auto[seg_min_x,seg_min_y,seg_max_x,seg_max_y] = seg_box.getBox(seg_x,seg_y,EntityID::SEGMENT);	

	auto laser_x = seg_max_x - Constants::LASER_HEIGHT_;
	auto laser_y = seg_max_y - Constants::LASER_HEIGHT_;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	
	auto[seg_get_x,seg_get_y] = segment.entityAttribute()->position()->getXYPosition();
	auto[laser_get_x,laser_get_y] = laser.entityAttribute()->position()->getXYPosition();

	CollisionDetection collision_detector(seg_get_x,seg_get_y,EntityID::SEGMENT,
										laser_get_x,laser_get_y,EntityID::LASER);

	CHECK(collision_detector.collided());
}//50-115assert

TEST_CASE("Bottom right of laser collides with top left of segment"){
	auto laser_x = 350.0f;
	auto laser_y = 300.0f;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	Box laser_box;
	auto[laser_min_x,laser_min_y,laser_max_x,laser_max_y] = laser_box.getBox(laser_x,laser_y,EntityID::LASER);
	
	auto seg_x = laser_max_x;
	auto seg_y = laser_max_y + Constants::LASER_HEIGHT_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[seg_get_x,seg_get_y] = segment.entityAttribute()->position()->getXYPosition();
	auto[laser_get_x,laser_get_y] = laser.entityAttribute()->position()->getXYPosition();

	CollisionDetection collision_detector(seg_get_x,seg_get_y,EntityID::SEGMENT,
										laser_get_x,laser_get_y,EntityID::LASER);

	CHECK(collision_detector.collided());
	
	
}//51-116assert
TEST_CASE("Laser and segment in different positions do not collide"){
	auto laser_x = 350.0f;
	auto laser_y = 300.0f;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	
	auto seg_x = 125.0f;
	auto seg_y = 225.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[seg_get_x,seg_get_y] = segment.entityAttribute()->position()->getXYPosition();
	auto[laser_get_x,laser_get_y] = laser.entityAttribute()->position()->getXYPosition();

	CollisionDetection collision_detector(seg_get_x,seg_get_y,EntityID::SEGMENT,
										laser_get_x,laser_get_y,EntityID::LASER);

	CHECK_FALSE(collision_detector.collided());
	
}//52-117assert

//**************************Laser-Mushroom Collision Tests***********************
TEST_CASE("Top right of laser collides with bottom left of Mushroom"){
	auto laser_x = 350.0f;
	auto laser_y = 300.0f;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	Box laser_box;
	auto[laser_min_x,laser_min_y,laser_max_x,laser_max_y] = laser_box.getBox(laser_x,laser_y,EntityID::LASER);
	
	auto mush_x = laser_max_x;
	auto mush_y = laser_max_y - Constants::MUSHROOM_HEIGHT_;
	
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);
	
	auto[get_laser_x,get_laser_y] = laser.entityAttribute()->position()->getXYPosition();
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_laser_x,get_laser_y,EntityID::LASER,
										  get_mush_x,get_mush_y,EntityID::MUSHROOM);
										  
	CHECK(collision_detector.collided());
	
}//53-118assert
TEST_CASE("Top left of laser collides with bottom right of mushroom"){
	
	auto mush_x = 250.0f;
	auto mush_y = 150.0f;
	
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);
	Box mush_box;
	auto[mush_min_x,mush_min_y,mush_max_x,mush_max_y] = mush_box.getBox(mush_x,mush_y,EntityID::MUSHROOM);
	
	auto laser_x = mush_max_x;
	auto laser_y = mush_max_y + Constants::MUSHROOM_HEIGHT_;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	
	auto[get_laser_x,get_laser_y] = laser.entityAttribute()->position()->getXYPosition();
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_laser_x,get_laser_y,EntityID::LASER,
										  get_mush_x,get_mush_y,EntityID::MUSHROOM);
										  
	CHECK(collision_detector.collided());
	
}//54-119assert

TEST_CASE("Laser situated directly below a mushroom collides with it"){
	auto laser_x = 125.0f;
	auto laser_y = 250.0f;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
	Box laser_box;
	auto[laser_min_x,laser_min_y,laser_max_x,laser_max_y] = laser_box.getBox(laser_x,laser_y,EntityID::LASER);

	auto mush_x = laser_max_x - Constants::MUSHROOM_WIDTH_/2.0;
	auto mush_y = laser_max_y - Constants::MUSHROOM_HEIGHT_;
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);
	
	auto[get_laser_x,get_laser_y] = laser.entityAttribute()->position()->getXYPosition();
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_laser_x,get_laser_y,EntityID::LASER,
										  get_mush_x,get_mush_y,EntityID::MUSHROOM);
										  
	CHECK(collision_detector.collided());
}//55-120assert

TEST_CASE("Laser and mushroom in different locations do not collide"){
	auto laser_x = 125.0f;
	auto laser_y = 250.0f;
	Laser laser(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
		
	auto mush_x = 50.0f;
	auto mush_y = 150.0f;
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);

	auto[get_laser_x,get_laser_y] = laser.entityAttribute()->position()->getXYPosition();
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_laser_x,get_laser_y,EntityID::LASER,
										  get_mush_x,get_mush_y,EntityID::MUSHROOM);
										  
	CHECK_FALSE(collision_detector.collided());
}//56-121assert

//**************************Centipede Tests****************************************
TEST_CASE("Cannot initialize Centipede with size <= 0"){
	
	CHECK_THROWS_AS(Centipede(-1),InsufficientCentipedeSize);
	CHECK_THROWS_AS(Centipede(0),InsufficientCentipedeSize);
	
}//57-123assert
//
TEST_CASE("Centipede's size has a limit"){
//	such that segments cannot be initialized out of bounds
//	NegativePosition exception from Position
//	 will be thrown for Centipede size > 26
	CHECK_THROWS(Centipede(27));
}//58-124assert

TEST_CASE("Centipede initializes a correct number of Segment objects"){
    auto number_of_segments = 5;
	auto incorrect_number_of_segments = 15;
    auto centipede_ = make_shared<Centipede>(number_of_segments);
    auto centipede_size = centipede_->getCentipede().size();
    CHECK(number_of_segments == centipede_size);
	CHECK_FALSE(centipede_size == incorrect_number_of_segments);
}//59-126assert
//
TEST_CASE("Centipede constructs segments in valid positions"){
	//Position does not throw exception for invalid position
	CHECK_NOTHROW(Centipede(20));
}
TEST_CASE("Centipede can move a segment"){
    
    auto centiSize = 1;
    Centipede centipede(centiSize);
    auto segment_iterator = begin(centipede.getCentipede());
    auto seg_x  = (*segment_iterator)->entityAttribute()->position()->getXPosition();
    auto x = 400.0f; //a set initial x-position of first segment

    CHECK(doctest::Approx(x) == seg_x);

    centipede.move();
    auto new_seg_x = (*segment_iterator)->entityAttribute()->position()->getXPosition();
    auto new_x = x + Constants::SEGMENT_SPEED_;
    CHECK(doctest::Approx(new_x) == new_seg_x);
    CHECK_FALSE(doctest::Approx(seg_x) == new_seg_x);
    
}//60-129assert
//
TEST_CASE("Centipede can move more than one segment"){

    auto centiSize = 2;
    auto centipede = make_shared<Centipede>(centiSize);
    auto segment_iterator = begin(centipede->getCentipede());
    auto seg_x_1 = (*segment_iterator)->entityAttribute()->position()->getXPosition();

    segment_iterator++;
    auto seg_x_2  = (*segment_iterator)->entityAttribute()->position()->getXPosition();
    centipede->move();
    segment_iterator--;
    auto new_seg_x_1 = (*segment_iterator)->entityAttribute()->position()->getXPosition();
    segment_iterator++;
    auto new_seg_x_2  = (*segment_iterator)->entityAttribute()->position()->getXPosition();
    auto new_x_1 = seg_x_1 + Constants::SEGMENT_SPEED_;   //segment speed is 4
    auto new_x_2 = seg_x_2 + Constants::SEGMENT_SPEED_;
    CHECK(doctest::Approx(new_x_1) == new_seg_x_1);
    CHECK(doctest::Approx(new_x_2) == new_seg_x_2);
    
}//61-131assert
//
TEST_CASE("Centipede moves a segment to the right if it is facing in the right direction"){
    auto centiSize = 1;
	Centipede centipede(centiSize);
	auto seg_iterator = begin(centipede.getCentipede());
	auto old_x_right = (*seg_iterator)->entityAttribute()->position()->getXPosition();
	//segment is facing right by default
	 centipede.move();
	 auto new_x_right = (*seg_iterator)->entityAttribute()->position()->getXPosition();
	 auto new_x = old_x_right + Constants::SEGMENT_SPEED_;
	 auto wrong_new_x = old_x_right - Constants::SEGMENT_SPEED_;
	 CHECK(doctest::Approx(new_x) == new_x_right);
	 CHECK_FALSE(doctest::Approx(wrong_new_x) == new_x_right);
	
}//62-133assert
//
TEST_CASE("Centipede moves a segment to the left if it is facing in the left direction"){
    auto centiSize = 1;
	Centipede centipede(centiSize);
	auto seg_iterator = begin(centipede.getCentipede());
	auto old_x_left = (*seg_iterator)->entityAttribute()->position()->getXPosition();
	(*seg_iterator)->faceLeft();
	centipede.move();
	auto new_x_left = (*seg_iterator)->entityAttribute()->position()->getXPosition();
	auto new_x = old_x_left - Constants::SEGMENT_SPEED_;
	auto wrong_new_x = old_x_left + Constants::SEGMENT_HEIGHT_;
	
	CHECK(doctest::Approx(new_x) == new_x_left);
	CHECK_FALSE(doctest::Approx(wrong_new_x) == new_x_left);
}//63-135assert
//
TEST_CASE(" while going down, Centipede moves a segment down and left when it reaches right border"){
    
    auto centiSize = 1;
	Centipede centipede(centiSize);
	auto seg_iterator = begin(centipede.getCentipede());
	auto[old_seg_x,old_seg_y] = (*seg_iterator)->entityAttribute()->position()->getXYPosition();
	auto x_right_border = 776.0f; //set internally
	(*seg_iterator)->entityAttribute()->position()->setXPosition(x_right_border);
	centipede.move();
	auto[new_seg_x,new_seg_y] = (*seg_iterator)->entityAttribute()->position()->getXYPosition();
	auto new_y = 16.0f;
	auto new_x = x_right_border - Constants::SEGMENT_SPEED_;
	CHECK(doctest::Approx(new_y) == new_seg_y);
	CHECK(doctest::Approx(new_x) == new_seg_x);

}//64-137assert

TEST_CASE("While going down, Centipede moves a segment down and right when it reaches left border"){
    auto centiSize = 1;
	Centipede centipede(centiSize);
	auto seg_iterator = begin(centipede.getCentipede());
	auto[old_seg_x,old_seg_y] = (*seg_iterator)->entityAttribute()->position()->getXYPosition();
	auto x_left_border = 4.0f; //set internally
	(*seg_iterator)->entityAttribute()->position()->setXPosition(x_left_border);
	
	(*seg_iterator)->faceLeft();	//enforcing direction 
	centipede.move();
	auto[new_seg_x,new_seg_y] = (*seg_iterator)->entityAttribute()->position()->getXYPosition();
	auto new_x = x_left_border + Constants::SEGMENT_SPEED_;
	auto new_y = old_seg_y + 4*(Constants::SEGMENT_SPEED_);
	
	CHECK(doctest::Approx(new_seg_x) == new_x);
	CHECK(doctest::Approx(new_y) == new_seg_y);
	
}//65-139assert

TEST_CASE("While going up, Centipede moves a segment up and left when it is at right border"){
    auto centiSize = 1;
	Centipede centipede(centiSize);
	auto seg_iterator = begin(centipede.getCentipede());
	auto x_right_border = 776.0f;
	auto y_position = 550.0f;
	(*seg_iterator)->entityAttribute()->position()->setXYPosition(x_right_border,y_position);
	(*seg_iterator)->faceUp();
	centipede.move();
	auto[new_seg_x,new_seg_y] = (*seg_iterator)->entityAttribute()->position()->getXYPosition();
	auto new_x = x_right_border - Constants::SEGMENT_SPEED_;
	auto new_y = y_position - 4.0*Constants::SEGMENT_SPEED_;
	
	CHECK(doctest::Approx(new_y) == new_seg_y);
	CHECK(doctest::Approx(new_x) == new_seg_x);
}//66-141assert

TEST_CASE("While going up, Centipede moves a segment up and right when it is at left border"){
    auto centiSize = 1;
	Centipede centipede(centiSize);
	auto seg_iterator = begin(centipede.getCentipede());
	auto x_left_border = 4.0f;
	auto y_position = 550.0f;
	(*seg_iterator)->entityAttribute()->position()->setXYPosition(x_left_border,y_position);
	(*seg_iterator)->faceUp();
	(*seg_iterator)->faceLeft();
	centipede.move();
	auto[new_seg_x,new_seg_y] = (*seg_iterator)->entityAttribute()->position()->getXYPosition();
	auto new_x = x_left_border + Constants::SEGMENT_SPEED_;
	auto new_y = y_position - 4.0*Constants::SEGMENT_SPEED_;
	
	CHECK(doctest::Approx(new_y) == new_seg_y);
	CHECK(doctest::Approx(new_x) == new_seg_x);
	
}//67-143assert
//
TEST_CASE("while moving up and at left border, Centipede moves a segment down when it reaches a set vertical limit"){
	auto centipedeSize = 1;
	Centipede centipede(centipedeSize);
	auto centipede_iterator = begin(centipede.getCentipede());
	auto x_i = 4.0;
	auto y_i = 450.0f;
	(*centipede_iterator)->entityAttribute()->position()->setXYPosition(x_i,y_i);
	(*centipede_iterator)->faceLeft();
	(*centipede_iterator)->faceUp();
	centipede.move();
	auto y_f = (*centipede_iterator)->entityAttribute()->position()->getYPosition();
	auto false_y_f = y_i - 4.0*Constants::SEGMENT_SPEED_;
	auto true_y_f = y_i + 4.0*Constants::SEGMENT_SPEED_;
	CHECK(doctest::Approx(y_f) == true_y_f);
	CHECK_FALSE(doctest::Approx(y_f) == false_y_f);
}
//
TEST_CASE("while moving up and at right border, Centipede moves a segment down when it reaches a set vertical limit"){
	auto centipedeSize = 1;
	Centipede centipede(centipedeSize);
	auto centipede_iterator = begin(centipede.getCentipede());
	auto x_i = 776.0f;
	auto y_i = 450.0f;
	
	(*centipede_iterator)->entityAttribute()->position()->setXYPosition(x_i,y_i);
	(*centipede_iterator)->faceRight();
	(*centipede_iterator)->faceUp();
	centipede.move();
	
	auto y_f = (*centipede_iterator)->entityAttribute()->position()->getYPosition();
	auto false_y_f = y_i - 4.0*Constants::SEGMENT_SPEED_;
	auto true_y_f = y_i + 4.0*Constants::SEGMENT_SPEED_;
	
	CHECK(doctest::Approx(y_f) == true_y_f);
	CHECK_FALSE(doctest::Approx(y_f) == 0.0);
}
//
TEST_CASE("while moving down and at bottom left corner, Centipede moves a segment up"){
	auto centipedeSize = 1;
	Centipede centipede(centipedeSize);
	auto centipede_iterator = begin(centipede.getCentipede());
	auto x_i = 4.0f;
	auto y_i = 584.0f;
	
	(*centipede_iterator)->entityAttribute()->position()->setXYPosition(x_i,y_i);
	(*centipede_iterator)->faceLeft();
	(*centipede_iterator)->faceDown();
	centipede.move();
	auto y_f = (*centipede_iterator)->entityAttribute()->position()->getYPosition();
	auto true_y_f = y_i - 4.0*Constants::SEGMENT_SPEED_;
	
	CHECK(doctest::Approx(y_f) == true_y_f);
	CHECK_FALSE(doctest::Approx(y_f) == y_i);
	
}
//
TEST_CASE("while moving down and at bottom right corner, Centipede moves a segment up"){
	auto centipedeSize = 1;
	Centipede centipede(centipedeSize);
	auto centipede_iterator = begin(centipede.getCentipede());
	auto x_i = 776.0f;
	auto y_i = 584.0f;
	
	(*centipede_iterator)->entityAttribute()->position()->setXYPosition(x_i,y_i);
	(*centipede_iterator)->faceRight();
	(*centipede_iterator)->faceDown();
	centipede.move();
	auto y_f = (*centipede_iterator)->entityAttribute()->position()->getYPosition();
	auto true_y_f = y_i - 4.0*Constants::SEGMENT_SPEED_;
	
	CHECK(doctest::Approx(y_f) == true_y_f);
	CHECK_FALSE(doctest::Approx(y_f) == y_i);
}

//************************Segment-Player Collision Tests****************************************
TEST_CASE("Top right corner of player collides with bottom left corner of segment"){
	auto player_x = 250.0f;
	auto player_y = 475.0f;
	Player player(player_x,player_y,EntityID::PLAYER,Constants::PLAYER_SPEED_);

	Box player_box;
	auto[p_min_x,p_min_y,p_max_x,p_max_y] = player_box.getBox(player_x,player_y,EntityID::PLAYER);
	
	auto seg_x = p_max_x;
	auto seg_y = p_max_y - Constants::SEGMENT_HEIGHT_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[get_player_x,get_player_y] = player.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_player_x,get_player_y,EntityID::PLAYER,
										  get_seg_x,get_seg_y,EntityID::SEGMENT);
										  
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());
}//72-152assert
//
TEST_CASE("Top left corner of player collides with bottom right corner of segment"){
	auto seg_x = 325.0f;
	auto seg_y = 550.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	Box seg_box;
	auto[seg_min_x,seg_min_y,seg_max_x,seg_max_y] = seg_box.getBox(seg_x,seg_y,EntityID::SEGMENT);
	
	auto player_x = seg_max_x;
	auto player_y = seg_max_y + Constants::SEGMENT_HEIGHT_;
	Player player(player_x,player_y,EntityID::PLAYER,Constants::PLAYER_SPEED_);
	
	auto[get_player_x,get_player_y] = player.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_player_x,get_player_y,EntityID::PLAYER,
										  get_seg_x,get_seg_y,EntityID::SEGMENT);
										  
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());

}//73-155assert
//
TEST_CASE("Bottom left corner of player collides with top right corner of segment"){
	auto seg_x = 325.0f;
	auto seg_y = 560.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	Box seg_box;
	auto[seg_min_x,seg_min_y,seg_max_x,seg_max_y] = seg_box.getBox(seg_x,seg_y,EntityID::SEGMENT);	
	auto player_x = seg_max_x;
	auto player_y = seg_max_y - Constants::PLAYER_HEIGHT_;
	Player player(player_x,player_y,EntityID::PLAYER,Constants::PLAYER_SPEED_);
	
	auto[get_player_x,get_player_y] = player.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_player_x,get_player_y,EntityID::PLAYER,
										  get_seg_x,get_seg_y,EntityID::SEGMENT);
										  
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());
	
}//74-157assert
//
TEST_CASE("Bottom right of player corner collides with top left corner of segment"){
	auto player_x = 350.0f;
	auto player_y = 475.0f;
	Player player(player_x,player_y,EntityID::PLAYER,Constants::PLAYER_SPEED_);	
	Box player_box;
	auto[p_min_x,p_min_y,p_max_x,p_max_y] = player_box.getBox(player_x,player_y,EntityID::PLAYER);
	auto seg_x = p_max_x;
	auto seg_y = p_max_y + Constants::PLAYER_HEIGHT_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);

	auto[get_player_x,get_player_y] = player.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_player_x,get_player_y,EntityID::PLAYER,
										  get_seg_x,get_seg_y,EntityID::SEGMENT);
										  
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());
}//75-159assert

//***************************Segment-Mushroom collision Tests*****************************
TEST_CASE("Top right corner of segment collides with bottom left corner mushroom"){
	
	auto seg_x = 150.0f;
	auto seg_y = 350.0f;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	Box seg_box;
	
	auto[seg_min_x,seg_min_y,seg_max_x,seg_max_y] = seg_box.getBox(seg_x,seg_y,EntityID::SEGMENT);
	auto mush_x = seg_max_x;
	auto mush_y = seg_max_y - Constants::MUSHROOM_HEIGHT_;
	Mushroom mushroom(mush_x,mush_y,EntityID::SEGMENT);
	
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detecttor(get_mush_x,get_mush_y,EntityID::MUSHROOM,
										   get_seg_x,get_seg_y,EntityID::SEGMENT);
										   
	
	CHECK(collision_detecttor.collided());
	CHECK_FALSE(!collision_detecttor.collided());
	
}//76-161Assert
//
TEST_CASE("Top left corner of segment collides with bottom right corner of mushroom"){
	auto mush_x = 625.0f;
	auto mush_y = 135.0f;
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);
	Box mush_box;
	auto[mush_min_x,mush_min_y,mush_max_x,mush_max_y] = mush_box.getBox(mush_x,mush_y,EntityID::MUSHROOM);
	auto seg_x = mush_max_x;
	auto seg_y = mush_max_y - Constants::SEGMENT_HEIGHT_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_mush_x,get_mush_y,EntityID::MUSHROOM,
										 get_seg_x,get_seg_y,EntityID::SEGMENT);
	
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());
}//77-163assert
TEST_CASE("Bottom left corner of segment collides with top right corner of mushroom"){
	auto mush_x = 325.0f;
	auto mush_y = 350.0f;
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);
	Box mushroom_box;
	auto[mush_min_x,mush_min_y,mush_max_x,mush_max_y] = mushroom_box.getBox(mush_x,mush_y,EntityID::MUSHROOM);
	auto seg_x = mush_max_x;
	auto seg_y = mush_max_y - Constants::SEGMENT_HEIGHT_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_mush_x,get_mush_y,EntityID::MUSHROOM,
										 get_seg_x,get_seg_y,EntityID::SEGMENT);
	
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());
	
}//78-165assert
//
TEST_CASE("Bottom right corner of segment collides with top left corner mushroom"){
	auto mush_x = 350.0f;
	auto mush_y = 12.0f;
	Mushroom mushroom(mush_x,mush_y,EntityID::MUSHROOM);
	Box mushBox;
	auto[m_min_x,m_min_y,m_max_x,m_max_y] = mushBox.getBox(mush_x,mush_y,EntityID::MUSHROOM);
	auto seg_x = m_min_x;
	auto seg_y = m_min_y - Constants::SEGMENT_HEIGHT_;
	Segment segment(seg_x,seg_y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	
	auto[get_mush_x,get_mush_y] = mushroom.entityAttribute()->position()->getXYPosition();
	auto[get_seg_x,get_seg_y] = segment.entityAttribute()->position()->getXYPosition();
	
	CollisionDetection collision_detector(get_mush_x,get_mush_y,EntityID::MUSHROOM,
										 get_seg_x,get_seg_y,EntityID::SEGMENT);
	
	CHECK(collision_detector.collided());
	CHECK_FALSE(!collision_detector.collided());
}
************************************************************************************************
//*******************************Collision-Reaction Tests**************************************
//
TEST_CASE("Collided lasers get erased"){
	
	auto x = 50.0f;
	auto y = 150.0f;
	
	auto laser = make_shared<Laser>(x,y,EntityID::LASER,Constants::LASER_SPEED_);
	laser->entityAttribute()->destroy();
	auto laser_2 = laser;
	auto laser_3 = laser;
	
	list<shared_ptr<Laser>>lasers;
	lasers.push_back(laser);
	lasers.push_back(laser_2);
	lasers.push_back(laser_3);
	
	CollisionReaction collision_reactor;
	collision_reactor.updateLasers(lasers);
	auto lasers_iterator = begin(lasers);
	auto lasersSize = 0;
	while(lasers_iterator != end(lasers)){
		++lasers_iterator;
		++lasersSize;
	}
	
	CHECK_EQ(lasersSize,0);
}
//
TEST_CASE("uncollided lasers do not get erased"){
	auto x = 50.0f;
	auto y = 150.0f;
	
	auto laser = make_shared<Laser>(x,y,EntityID::LASER,Constants::LASER_SPEED_);

	auto laser_2 = laser;
	auto laser_3 = laser;
	
	list<shared_ptr<Laser>>lasers;
	lasers.push_back(laser);
	lasers.push_back(laser_2);
	lasers.push_back(laser_3);
	
	CollisionReaction collision_reactor;
	collision_reactor.updateLasers(lasers);
	auto lasers_iterator = begin(lasers);
	auto lasersSize = 0;
	while(lasers_iterator != end(lasers)){
		++lasers_iterator;
		++lasersSize;
	}
		
	CHECK_NE(lasersSize,0);	
}
//
TEST_CASE("Collided segments get erased"){
	
	auto x = 150.0f;
	auto y = 205.0f;
	
	auto segment = make_shared<Segment>(x,y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
	segment->entityAttribute()->destroy();
	auto segment_2 = segment;
	auto segment_3 = segment;
	
	list<shared_ptr<Segment>>segments;
	segments.push_back(segment);
	segments.push_back(segment_2);
	segments.push_back(segment_3);
	auto field = make_shared<Field>(1);
	
	CollisionReaction collision_reactor;
	collision_reactor.updateSegments(segments,field);
	
	auto seg_iterator = begin(segments);
	auto segmentsSize = 0;
	while(seg_iterator != end(segments)){
		++seg_iterator;
		++segmentsSize;
	}
	
	CHECK_EQ(segmentsSize,0);
}
//
TEST_CASE("uncollided segments do not get erased"){
	auto x = 150.0f;
	auto y = 205.0f;
	
	auto segment = make_shared<Segment>(x,y,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);

	auto segment_2 = segment;
	auto segment_3 = segment;
	
	list<shared_ptr<Segment>>segments;
	segments.push_back(segment);
	segments.push_back(segment_2);
	segments.push_back(segment_3);
	auto field = make_shared<Field>(1);
	
	CollisionReaction collision_reactor;
	collision_reactor.updateSegments(segments,field);
	
	auto seg_iterator = begin(segments);
	auto segmentsSize = 0;
	while(seg_iterator != end(segments)){
		++seg_iterator;
		++segmentsSize;
	}
	
	CHECK_NE(segmentsSize,0);
}
//
TEST_CASE("destroyed mushrooms get destroyed"){
	
	auto x = 100.0f;
	auto y = 36.0f;
	
	auto mushroom = make_shared<Mushroom>(x,y,EntityID::MUSHROOM);
	mushroom->entityAttribute()->destroy();
	auto mushroom_2 = mushroom;
	auto mushroom_3 = mushroom;
	list<shared_ptr<Mushroom>>mushrooms;
	mushrooms.push_back(mushroom);
	mushrooms.push_back(mushroom_2);
	mushrooms.push_back(mushroom_3);
	
	CollisionReaction collision_reactor;
	collision_reactor.updateMushrooms(mushrooms);
	auto mush_iterator = begin(mushrooms);
	auto numberOfMushrooms = 0;
	while(mush_iterator != end(mushrooms)){
		++mush_iterator;
		++numberOfMushrooms;
	}
	
	CHECK_EQ(numberOfMushrooms,0);
}
//
TEST_CASE("Mushrooms not erased if not destroyed"){
	auto x = 100.0f;
	auto y = 36.0f;
	
	auto mushroom = make_shared<Mushroom>(x,y,EntityID::MUSHROOM);

	auto mushroom_2 = mushroom;
	auto mushroom_3 = mushroom;
	list<shared_ptr<Mushroom>>mushrooms;
	mushrooms.push_back(mushroom);
	mushrooms.push_back(mushroom_2);
	mushrooms.push_back(mushroom_3);
	
	CollisionReaction collision_reactor;
	collision_reactor.updateMushrooms(mushrooms);
	auto mush_iterator = begin(mushrooms);
	auto numberOfMushrooms = 0;
	while(mush_iterator != end(mushrooms)){
		++mush_iterator;
		++numberOfMushrooms;
	}
	
	CHECK_NE(numberOfMushrooms,0);	
}