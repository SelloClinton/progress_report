#include "Box.h"

Box::Box()
{
}
	
tuple<float,float,float,float> Box::getBox(float x, float y, const EntityID& object){
	auto[min_x,min_y,max_x,max_y] =  createBox(x, y, object);
	return {min_x,min_y,max_x,max_y};
}

tuple<float,float,float,float> Box::createBox(float x, float y, const EntityID& object){
	
	switch(object){
			case EntityID::LASER:
				return{x,(y+2*Constants::LASER_HEIGHT_),(x+2*Constants::LASER_WIDTH_),y};
				break;
			case EntityID::MUSHROOM:
				return{x,(y+Constants::PLAYER_HEIGHT_),(x+Constants::PLAYER_WIDTH_),y};
			case EntityID::PLAYER:
			case EntityID::SEGMENT:
				return{x,(y+Constants::PLAYER_HEIGHT_),(x+Constants::PLAYER_WIDTH_),y};
				break;
			default:
				assert(false);
		
	}
}