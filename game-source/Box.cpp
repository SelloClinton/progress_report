#include "Box.h"

Box::Box()
//	position_(position)
{
}
	
tuple<int,int,int,int> Box::getBox(int x, int y, Object object){
	auto[min_x,min_y,max_x,max_y] =  createBox(x, y, object);
	return {min_x,min_y,max_x,max_y};
}

tuple<int,int,int,int> Box::createBox(int x, int y, Object object){
//	auto[x,y] = position_.getPosition();	
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