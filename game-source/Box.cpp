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
				return{x,(y+Constants::LASER_HEIGHT_),(x+Constants::LASER_WIDTH_),y};
				break;
			case EntityID::MUSHROOM:
				return{x,(y+Constants::MUSHROOM_HEIGHT_),(x+Constants::MUSHROOM_WIDTH_),y};
				break;
			case EntityID::PLAYER:
				return{x,(y+Constants::PLAYER_HEIGHT_),(x+Constants::PLAYER_WIDTH_),y};
				break;
			case EntityID::SEGMENT:
				return{x,(y+Constants::SEGMENT_HEIGHT_),(x+Constants::SEGMENT_WIDTH_),y};
				break;
			default:
				assert(false);
		
	}
}