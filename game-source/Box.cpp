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
	auto bullet_x_increment = 1;
	auto bullet_y_increment = 7;
	auto player_x_increment = 7;
	auto player_y_increment = 8;
	
	switch(object){
			case Object::BULLET:
				return{x,(y+bullet_y_increment),(x+bullet_x_increment),y};
				break;
			case Object::PLAYER:
			case Object::SEGMENT:
				return{x,(y+player_y_increment),(x+player_x_increment),y};
				break;
			default:
				assert(false);
		
	}
}