#include "Box.h"

Box::Box(Position position):
	position_(position)
{
}
	
tuple<int,int,int,int> Box::getBox(Object object){
	auto[min_x,min_y,max_x,max_y] =  createBox(object);
	return {min_x,min_y,max_x,max_y};
}

tuple<int,int,int,int> Box::createBox(Object object){
	auto[x,y] = position_.getPosition();	
	switch(object){
			case Object::BULLET:
				return{x,(y+Constants::BULLET_HEIGHT_),(x+Constants::BULLET_WIDTH_),y};
				break;
			case Object::PLAYER:
			case Object::SEGMENT:
				return{x,(y+Constants::PLAYER_HEIGHT_),(x+Constants::PLAYER_WIDTH_),y};
				break;
			default:
				assert(false);
		
	}
}