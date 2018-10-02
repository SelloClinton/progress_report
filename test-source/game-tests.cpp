#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source/Position.h"
#include "../game-source/Entity.h"
#include "../game-source/Mover.h"
#include "../game-source/Laser.h"
#include "../game-source/Player.h"
//#include "../game-source-code/Constants.h"
//#include "../game-source-code/Bullet.h"
#include "../game-source/Segment.h"
//#include "../game-source-code/Enums.h"
//#include "../game-source-code/Centipede.h"
#include "../game-source/Mushroom.h"
#include "../game-source/Field.h"


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
TEST_CASE("XY Getter function returns expected values"){
	
	auto x = 800.0f;
	auto y = 600.0f;
	Position position(x,y);	
	auto[x_position,y_position] = position.getXYPosition();
	CHECK(doctest::Approx(x) == x_position);
	CHECK(doctest::Approx(y) == y_position);
	CHECK_FALSE(doctest::Approx(x) == y_position);
	CHECK_FALSE(doctest::Approx(y) == x_position);
	
}//5-14assert
TEST_CASE("x position setter function returns expected value"){
	auto x = 800.0f;
	auto y = 600.0f;
	Position position(x,y);
	auto new_x = 450.0f;
	position.setXPosition(new_x);
	CHECK(doctest::Approx(new_x) == position.getXPosition());
	CHECK_FALSE(doctest::Approx(x) == position.getXPosition());
}//6-16assert
TEST_CASE("y position setter function returns expected value"){
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
	Position set_position(x,y);
	auto[oldXPosition,oldYPosition] = set_position.getXYPosition();
	auto new_x = 800.0f;
	auto new_y = 600.0f;
	set_position.setXYPosition(new_x,new_y);
	auto[newXPosition,newYPosition] = set_position.getXYPosition();
	
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
TEST_CASE("Valid position is returned"){
	
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	
	auto entity = make_shared<Entity>(x,y,id);
	CHECK(doctest::Approx(x) == entity->position()->getXPosition());
	CHECK(doctest::Approx(y) == entity->position()->getYPosition());
	
	auto[entity_x,entity_y] = entity->position()->getXYPosition();
	CHECK(doctest::Approx(entity_x) == x);
	CHECK(doctest::Approx(entity_y) == y);
	
}//10-28assert
TEST_CASE("Position is effectively set"){
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

TEST_CASE("Entity live state is true upon construction"){
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	auto entity = make_shared<Entity>(x,y,id);
	CHECK(entity->isLive());
	CHECK_FALSE(!entity->isLive());
}//12-34assert
TEST_CASE("Entity can be destroyed"){
	auto x = 50.0f;
	auto y = 150.0f;
	auto id = EntityID::PLAYER;
	auto entity = make_shared<Entity>(x,y,id);
	entity->destroy();
	CHECK_FALSE(entity->isLive());
}//13-35assert

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
TEST_CASE("Laser cannot have <= 0 speed"){
	
	CHECK_THROWS_AS(Laser(50,50,EntityID::LASER,-10),NegativeZeroLaserSpeed);
	CHECK_THROWS_AS(Laser(100,250,EntityID::LASER,0),NegativeZeroLaserSpeed);
	
}//15-39assert
TEST_CASE("Cannot construct A Laser with a wrong Entity ID"){
		CHECK_THROWS_AS(Laser(250,550,EntityID::PLAYER,4.0),IncorrectLaserEntityID);
		CHECK_THROWS_AS(Laser(400,250,EntityID::MUSHROOM,4.0),IncorrectLaserEntityID);
		CHECK_THROWS_AS(Laser(400,250,EntityID::SEGMENT,4.0),IncorrectLaserEntityID);
}//16-42ASSERT
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
}//17-43assert
TEST_CASE("Cannot update Laser movement if it is out of bound"){
	auto x = 250.0f;
	auto y = 0.0f;
	auto id = EntityID::LASER;
	auto speed = 4.0f;
	Laser laser(x,y,id,speed);
	auto old_y = laser.entityAttribute()->position()->getYPosition();
	laser.updatePosition();
	auto new_y = laser.entityAttribute()->position()->getYPosition(); 
	CHECK(doctest::Approx(new_y) == old_y);
	CHECK_FALSE(doctest::Approx(new_y) == old_y-speed);
}//18-45aseert
TEST_CASE("Laser gets destroyed when it goes out of screen bound"){
	auto x = 250.0f;
	auto y = 10.0f;
	auto id = EntityID::LASER;
	auto speed = 4.0f;
	Laser laser(x,y,id,speed);
	CHECK(laser.entityAttribute()->isLive());
	laser.updatePosition();
	CHECK_FALSE(laser.entityAttribute()->isLive());
}//19-47assert
TEST_CASE("x position of Laser does not get Updated when updating y position"){
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
	auto y = 450.0f;
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
	auto y = 584.0f;
	auto id = EntityID::PLAYER;
	auto speed = Constants::PLAYER_SPEED_;
	Player player(x,y,id,speed);
	auto old_y = player.entityAttribute()->position()->getYPosition();
	player.move(Direction::DOWN);
	auto new_y = player.entityAttribute()->position()->getYPosition();
	CHECK(doctest::Approx(new_y) == old_y);
	CHECK_FALSE(doctest::Approx(new_y) == old_y+speed);		
}//30-70assert
//*****************************************************************************
//**************************Mushroom Tests**********************************
TEST_CASE("Mushroom dies after being weakened four times"){
	auto mushroom_x_position = 320.0f;
	auto mushroom_y_position = 250.0f;
	auto mushroom_entity = EntityID::MUSHROOM;
	auto mushroom = make_shared<Mushroom>(mushroom_x_position,mushroom_y_position,mushroom_entity);
	
	auto hits = 4;
	for(auto i = 0; i != hits; i++)
		mushroom->weaken();
	CHECK_FALSE(mushroom->entityAttribute()->isLive());
	
}//31-71assert
//
TEST_CASE("Mushroom does not die if hit less than four times"){
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
//**********************************************************************************
//***************************Segment Tests*****************************************
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



//**************************Mover tests********************************************
//TEST_CASE("Speed cannot be less than or equal to zero"){
//	auto x = 150.0f;
//	auto y = 250.0f;
//	auto negative_speed = -10;
//	CHECK_THROWS_AS(Mover(x,y,negative_speed),NegativeZeroSpeed);
//	auto zero_speed = 0;
//	CHECK_THROWS_AS(Mover(x,y,zero_speed),NegativeZeroSpeed);
//}//14-39assert
//
//TEST_CASE("Mover Position attribute returns correct values"){
//
//	auto x = 400.0f;
//	auto y = 300.0f;
//	auto speed = 5.0f;
//	
//	auto mover = make_unique<Mover>(x,y,speed);
//		
//	auto[x_,y_] = mover->position();
//
//	CHECK(doctest::Approx(x) == x_);
//	CHECK(doctest::Approx(y) == y_);
//}//15-41assert
//
//TEST_CASE("Mover can move up"){
//	
//	auto x = 784.0f;
//	auto y = 584.0f;
//	auto speed = 5.0f;
//	
//	auto mover = make_unique<Mover>(x,y,speed);	
//	auto[x_,y_] = mover->position();
//	mover->moveRight();
//	auto[new_x,new_y] = mover->position();
//	
//        
//	CHECK(doctest::Approx(new_x) == x_+speed);
////	CHECK(new_y == new_y_position);
////	CHECK_FALSE(x_attribute == new_x_position);
////	CHECK_FALSE(y_attribute == new_y_position);
//        
//}//16-
//
//TEST_CASE("Position attribute changes accordingly when moving left"){
//	
//		auto position = make_shared<Position>(400,300);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::LEFT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 395;
//		auto new_y = 300;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//        CHECK_FALSE(old_y_pos != new_y_pos);
//		CHECK_FALSE(old_x_pos == new_x_pos);
//}//9
//
//TEST_CASE("Cannot move left when x position is zero"){
//		auto position = make_shared<Position>(0,300);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::LEFT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 0;
//		CHECK(new_x == new_x_pos);
//		CHECK(old_y_pos == new_y_pos);
//		CHECK_FALSE(old_x_pos != new_x_pos);
//}//10
//
//TEST_CASE("Position attribute returns correct values after moving right"){
//	
//		auto position = make_shared<Position>(300,400);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::RIGHT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 305;
//		CHECK(new_x == new_x_pos);
//		CHECK(old_y_pos == new_y_pos);
//		CHECK_FALSE(old_x_pos == new_x_pos);
//}//11
//
//TEST_CASE("Cannot move right when x = Display width"){
//		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_-(Constants::PLAYER_WIDTH_/2),500);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::RIGHT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = Constants::DISPLAY_WIDTH_-(Constants::PLAYER_WIDTH_/2);
//		CHECK(new_x == new_x_pos);
//		CHECK(old_y_pos == new_y_pos);
//		CHECK_FALSE(old_x_pos != new_x_pos);		
//}//12
//
//TEST_CASE("Position attribute changes accordingly when moving up"){
//		auto position = make_shared<Position>(300,400);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::UP);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_y = 395;
//		CHECK(old_x_pos == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos == new_y_pos);
//}//13
//
//TEST_CASE("Cannot move up at y = 0"){
//		auto position = make_shared<Position>(300,Constants::PLAYER_HEIGHT_/2);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::UP);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 300;
//		auto new_y = Constants::PLAYER_HEIGHT_/2;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos != new_y_pos);
//}//14
//
//TEST_CASE("Position attributes changes accordingly when moving down"){
//		auto position = make_shared<Position>(200,300);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::DOWN);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 200;
//		auto new_y = 305;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos == new_y_pos);		
//}//15
//
//TEST_CASE("Cannot move down when y = screen height"){
//		auto position = make_shared<Position>(300,Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2));
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::DOWN);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 300;
//		auto new_y = Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2);
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos != new_y_pos);	
//}//16
//
//TEST_CASE("Mover's isLive() behaves as expected'"){
//    
//    auto position = make_shared<Position>(150,250);
//    auto mover = make_shared<Mover>(position,Constants::BULLET_SPEED_);
//    bool live = true;
//    bool dead = false;
//    auto mover_life = mover->isLive();
//    CHECK(live == mover_life);
//    CHECK_FALSE(dead == mover_life);
//}//17
//
//TEST_CASE("Mover's destroy() behaves as expected"){
//    auto position = make_shared<Position>(150,250);
//    auto mover = make_shared<Mover>(position,Constants::BULLET_SPEED_);
//    bool live = true;
//    bool dead = false;
//    auto mover_life = mover->isLive();
//    CHECK(live == mover_life);
//    CHECK_FALSE(dead == mover_life);
//    
//    mover->destroy();
//    mover_life = mover->isLive();
//    
//    CHECK(mover_life == dead);
//    CHECK_FALSE(mover_life == live);
//        
//}//18
//
//
////*****************************Player tests**********************************
//TEST_CASE("Position getter of Player returns correct values"){
//		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_/2,Constants::DISPLAY_HEIGHT_-10);
//		int speed = 5;
//		auto mover = make_shared<Mover>(position,speed);
//		auto player = make_shared<Player>(mover);
//		
//		auto[x_position,y_position] = player->attribute()->position()->getPosition();
//		auto x = Constants::DISPLAY_WIDTH_/2;
//		auto y = Constants::DISPLAY_HEIGHT_-10;
//		
//		CHECK(x_position == x);
//		CHECK(y == y_position);
//}//19
//
//TEST_CASE("Position setter of Player behaves as expected"){
//	
//		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_/2,Constants::DISPLAY_HEIGHT_-10);
//		int speed = 5;
//		auto mover = make_shared<Mover>(position,speed);
//		auto player = make_shared<Player>(mover);
//		
//		auto[x_position,y_position] = player->attribute()->position()->getPosition();
//	
//		auto new_x = 10;
//		auto new_y = 100;
//		
//		player->attribute()->position()->setPosition(new_x,new_y);
//		
//		auto[new_x_position,new_y_position] = player->attribute()->position()->getPosition();
//		
//		
//		CHECK(new_x == new_x_position);
//		CHECK(new_y == new_y_position);
//		CHECK_FALSE(x_position == new_x_position);
//		CHECK_FALSE(y_position == new_y_position);
//
//}//20
//
//TEST_CASE("Player's basic move right works properly"){
//    
//		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_/2,Constants::DISPLAY_HEIGHT_-10);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->attribute()->move(Direction::RIGHT);
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		auto x = Constants::DISPLAY_WIDTH_/2+player_speed;
//		
//		CHECK(x == new_x);
//		CHECK(old_y == new_y);
//		CHECK_FALSE(old_x == new_x);
//		
//}//21
//TEST_CASE("Cannot move player to the right beyond screen border"){
//    //the limit occurs at x = 784
//		auto position = make_shared<Position>(784,450);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->attribute()->move(Direction::RIGHT);
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		
//		CHECK(old_x == new_x);    
//}//22
//TEST_CASE("Player's basic move left works properly"){
//		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_/2,Constants::DISPLAY_HEIGHT_-10);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->attribute()->move(Direction::LEFT);
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		auto x = Constants::DISPLAY_WIDTH_/2-player_speed;
//		
//		CHECK(x == new_x);
//		CHECK(old_y == new_y);
//		CHECK_FALSE(old_x == new_x);
//		
//		
//}//23
//TEST_CASE("Cannot move player to the left beyond screen border"){
//        //the limit occurs at x = 0
//		auto position = make_shared<Position>(0,450);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->attribute()->move(Direction::LEFT);
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		
//		CHECK(old_x == new_x);  
//}//24
//
//TEST_CASE("Player's basic move up works properly"){
//    
//		auto position = make_shared<Position>(400,590);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->moveUp();
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		auto y = 585;
//		
//		CHECK(y == new_y);
//		CHECK(old_x == new_x);
//		CHECK_FALSE(old_y == new_y);
//		
//		
//}//25
//TEST_CASE("Cannot move player up after reaching a set limit"){
//    //the limit occurs at y = 450
//		auto position = make_shared<Position>(400,450);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->moveUp();
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		auto y = 450;
//		
//		CHECK(y == new_y);
//}//26
//
//TEST_CASE("Player's basic move down works properly"){
//    
//		auto position = make_shared<Position>(400,500);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->attribute()->move(Direction::DOWN);
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//		auto y = 505;
//		
//		CHECK(y == new_y);
//		CHECK(old_x == new_x);
//		CHECK_FALSE(old_y == new_y);
//		
//		
//}//27
//
//TEST_CASE("Cannot move player down beyond bottom of the screen"){
//    
//		auto position = make_shared<Position>(400,584);
//		auto player_speed = 5;
//		auto mover = make_shared<Mover>(position,player_speed);
//		auto player = make_shared<Player>(mover);
//		auto[old_x,old_y] = player->attribute()->position()->getPosition();
//		player->attribute()->move(Direction::DOWN);
//		auto[new_x,new_y] = player->attribute()->position()->getPosition();
//        
//        CHECK(old_y == new_y);
//        
//}//28
//
////**********************Bullet Tests******************************************
//TEST_CASE("Bullet's basic move function behaves as expected"){
//	
//	auto bullet_position = make_shared<Position>(250,350);
//	auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
//	auto bullet = make_shared<Bullet>(bullet_mover);
//	auto[x,y] = bullet->attribute()->position()->getPosition();
//	auto x_pos = 250;
//	auto y_pos = 350;
//	CHECK(x == x_pos);
//	CHECK(y == y_pos);
//	CHECK_FALSE(x == y_pos);
//	CHECK_FALSE(y == x_pos);
//	
//}//29
////
//TEST_CASE("Cannot move bullet beyond screen borders"){
//	
//	auto bullet_position = make_shared<Position>(250,0);
//	auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
//	auto bullet = make_shared<Bullet>(bullet_mover);
//	auto[x_i,y_i] = bullet->attribute()->position()->getPosition();
//	bullet->move();
//	auto[x_f,y_f] = bullet->attribute()->position()->getPosition();
//	CHECK(y_i == y_f);
//}//30
////
//TEST_CASE("Bullet gets destroyed as it goes out of screen"){
//	
//	auto bullet_position = make_shared<Position>(250,0);
//	auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
//	auto bullet = make_shared<Bullet>(bullet_mover);
//	auto bullet_life = bullet->attribute()->isLive();
//	CHECK(bullet_life);
//	bullet->move();
//	bullet_life = bullet->attribute()->isLive();
//	CHECK_FALSE(bullet_life);
//	
//}//31
//
////***********************************************************************
//
////******************************Segment Tests**********************************
//TEST_CASE("faceLeft and isFacingLeft functions behave as expected"){
//	auto segment_position = make_shared<Position>(40,150);
//	auto segment_mover = make_shared<Mover>(segment_position,Constants::SEGMENT_SPEED_);
//	auto segment = make_shared<Segment>(segment_mover);
//	segment->faceLeft();
//	CHECK(segment->isFacingLeft());
//	CHECK_FALSE(!segment->isFacingLeft());
//}//32
////
//TEST_CASE("faceRight and isFacingRight functions behave as expected"){
//	auto segment_position = make_shared<Position>(40,150);
//	auto segment_mover = make_shared<Mover>(segment_position,Constants::SEGMENT_SPEED_);
//	auto segment = make_shared<Segment>(segment_mover);
//	segment->faceRight();
//	CHECK(segment->isFacingRight());
//	CHECK_FALSE(!segment->isFacingRight());
//}//33
////
//TEST_CASE("faceUp and isFacingUp functions behave as expected"){
//	auto segment_position = make_shared<Position>(40,150);
//	auto segment_mover = make_shared<Mover>(segment_position,Constants::SEGMENT_SPEED_);
//	auto segment = make_shared<Segment>(segment_mover);
//	segment->faceUp();
//	CHECK(segment->isFacingUp());
//	CHECK_FALSE(!segment->isFacingUp());
//}//34
////
////
//TEST_CASE("faceDown and isFacingDown functions behave as expected"){
//	auto segment_position = make_shared<Position>(40,150);
//	auto segment_mover = make_shared<Mover>(segment_position,Constants::SEGMENT_SPEED_);
//	auto segment = make_shared<Segment>(segment_mover);
//	segment->faceDown();
//	CHECK(segment->isFacingDown());
//	CHECK_FALSE(!segment->isFacingDown());
//}//35
////
//TEST_CASE("Segment cannot face left and right at the same time upon"){
//	auto segment_position = make_shared<Position>(40,150);
//	auto segment_mover = make_shared<Mover>(segment_position,Constants::SEGMENT_SPEED_);
//	auto segment = make_shared<Segment>(segment_mover);
//	auto left = segment->isFacingLeft();
//	auto right = segment->isFacingRight();
//	
//	CHECK_FALSE(right == left);
//}//36
////
//TEST_CASE("Segment cannot face up and down at the same time"){
//	auto segment_position = make_shared<Position>(40,150);
//	auto segment_mover = make_shared<Mover>(segment_position,Constants::SEGMENT_SPEED_);
//	auto segment = make_shared<Segment>(segment_mover);
//	auto up = segment->isFacingUp();
//	auto down = segment->isFacingDown();
//	
//	CHECK_FALSE(up == down);		
//}//37
////
//TEST_CASE("Segment's basic move right works properly"){
//		auto position = make_shared<Position>(250,250);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::RIGHT);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//		auto x = 254;
//		
//		CHECK(x == new_x);
//		CHECK(old_y == new_y);
//		CHECK_FALSE(old_x == new_x);
//		
//}//38
////
//TEST_CASE("Cannot move segment to the right beyond screen borders"){
//    
//		auto position = make_shared<Position>(784,250);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::RIGHT);
//        auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//        CHECK(old_y == new_y);
//}//39
//TEST_CASE("Segment's basic move left works properly"){
//	
//		auto position = make_shared<Position>(250,250);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::LEFT);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//		auto x = 246;
//		
//		CHECK(x == new_x);
//		CHECK(old_y == new_y);
//		CHECK_FALSE(old_x == new_x);
//		
//}//40
////
//TEST_CASE("Cannot move segment to the left beyond screen borders"){
//        auto position = make_shared<Position>(0,250);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::LEFT);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//        
//        CHECK(old_x == new_x);
//        
//}//41
//TEST_CASE("Segment's basic move down works properly"){
//	
//		auto position = make_shared<Position>(250,250);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::DOWN);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//		auto y = 254;
//		
//		CHECK(y == new_y);
//		CHECK(old_x == new_x);
//		CHECK_FALSE(old_y == new_y);
//		
//}//42
////
//TEST_CASE("Cannot move segment down beyond screen borders"){
//        auto position = make_shared<Position>(250,584);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::DOWN);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//        
//        CHECK(old_y == new_y);
//        
//}//43
//TEST_CASE("Segment's basic move up works properly"){
//	
//		auto position = make_shared<Position>(250,250);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::UP);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//		auto y = 246;
//		
//		CHECK(y == new_y);
//		CHECK(old_x == new_x);
//		CHECK_FALSE(old_y == new_y);
//		
//}//44
////
//TEST_CASE("Cannot move segment up beyond screen borders"){
//        auto position = make_shared<Position>(250,0);
//		auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
//		auto segment = make_shared<Segment>(mover);
//		auto[old_x,old_y] = segment->attribute()->position()->getPosition();
//		segment->attribute()->move(Direction::UP);
//		auto[new_x,new_y] = segment->attribute()->position()->getPosition();
//        
//        CHECK(old_y == new_y);
//        
//}//45
//////*******************************************************************
////*************************Mushroom Tests*****************************
//TEST_CASE("Mushroom's position getter returns correct results"){
//    auto mush_position = make_shared<Position>(50,250);
//    auto mushroom = make_shared<Mushroom>(mush_position);
//    auto[mush_x,mush_y] = mushroom->position()->getPosition();
//    auto x = 50;
//    auto y = 250;
//    
//    CHECK(x == mush_x);
//    CHECK(y == mush_y);
//    CHECK_FALSE(mush_x == mush_y);
//}//46
//////***********************Centipede Tests****************************
//TEST_CASE("Cannot initialize Centipede with size <= 0"){
//	
//	CHECK_THROWS_AS(Centipede(-25),InsufficientCentipedeSize);
//	CHECK_THROWS_AS(Centipede(0),InsufficientCentipedeSize);
//	
//}//47
////
//TEST_CASE("Centipede's size has a limit"){
//	//such that segments cannot be initialized out of bounds
//	//NegativePosition exception from Position
//	// will be thrown for Centipede size > 26
//	CHECK_THROWS(Centipede(27));
//}//48
//TEST_CASE("Centipede initializes a correct number of Segment objects"){
//    auto number_of_segments = 5;
//    auto centipede_ = make_shared<Centipede>(number_of_segments);
//    auto centipede_size = centipede_->getCentipede().size();
//    CHECK(number_of_segments == centipede_size);
//}//49
//TEST_CASE("Centipede can move a segment"){
//    
//    auto centiSize = 1;
//    auto centipede = make_shared<Centipede>(centiSize);
//    auto segment_iterator = begin(centipede->getCentipede());
//    auto[seg_x,seg_y] = (*segment_iterator)->attribute()->position()->getPosition();
//    auto x = 400;
//    auto y = 0;
//    
//    CHECK(x == seg_x);
//    CHECK(y == seg_y);
//    
//    centipede->moveSegments();
//    auto[new_seg_x,new_seg_y] = (*segment_iterator)->attribute()->position()->getPosition();
//    auto new_x = 404;
//    CHECK(new_x == new_seg_x);
//    CHECK_FALSE(new_seg_y != y);
//    
//}//50
//
//TEST_CASE("Centipede can move more than one segment"){
//
//    auto centiSize = 2;
//    auto centipede = make_shared<Centipede>(centiSize);
//    auto segment_iterator = begin(centipede->getCentipede());
//    auto[seg_x_1,seg_y_1] = (*segment_iterator)->attribute()->position()->getPosition();
//
//    segment_iterator++;
//    auto[seg_x_2,seg_y_2] = (*segment_iterator)->attribute()->position()->getPosition();
//    centipede->moveSegments();
//    segment_iterator--;
//    auto[new_seg_x_1,new_seg_y_1] = (*segment_iterator)->attribute()->position()->getPosition();
//    segment_iterator++;
//    auto[new_seg_x_2,new_seg_y_2] = (*segment_iterator)->attribute()->position()->getPosition();
//    auto new_x_1 = seg_x_1+4;   //segment speed is 4
//    auto new_x_2 = seg_x_2+4;
//    CHECK(new_x_1 == new_seg_x_1);
//    CHECK(new_x_2 == new_seg_x_2);
//    
//}//51
//
//TEST_CASE("Centipede moves a segment down when it reaches right border"){
//    
//    auto centiSize = 1;
//    auto centipede = make_shared<Centipede>(centiSize);
//    auto segment_iterator = begin(centipede->getCentipede());
//    auto[seg_x_1,seg_y_1] = (*segment_iterator)->attribute()->position()->getPosition();
//    auto x_border = 774;
//    
//    while(seg_x_1 <= x_border){
//        centipede->moveSegments();
//        seg_x_1 = get<0>((*segment_iterator)->attribute()->position()->getPosition());
//    }
//    
//    centipede->moveSegments();
//    seg_y_1 = get<1>((*segment_iterator)->attribute()->position()->getPosition());
//    auto new_y = 16;
//    
//    CHECK(seg_y_1 == new_y);
//    
//}//52
//
//TEST_CASE("Centipede can move a segment down when it reaches left border"){
//
//    auto centiSize = 1;
//    auto centipede = make_shared<Centipede>(centiSize);
//    auto segment_iterator = begin(centipede->getCentipede());
//    (*segment_iterator)->faceLeft();
//    auto[seg_x_1,seg_y_1] = (*segment_iterator)->attribute()->position()->getPosition();
//    
//    auto x_border = 5;
//    while(seg_x_1 >= x_border){
//        centipede->moveSegments();
//        seg_x_1 = get<0>((*segment_iterator)->attribute()->position()->getPosition());
//    }
//    
//    centipede->moveSegments();
//    seg_y_1 = get<1>((*segment_iterator)->attribute()->position()->getPosition());
//    
//    auto new_y_ =  16;
//    CHECK(seg_y_1 == new_y_);
//    
//    
//    
//}//53

