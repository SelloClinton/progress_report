#include "Mushroom.h"

Mushroom::Mushroom(shared_ptr<Position>position):
		  position_(position)
		  ,number_of_lives(4)
		  ,live_(false)
		  {}
		  
shared_ptr<Position> Mushroom::position(){
		return position_;
}
bool Mushroom::isLive()const{
		return live_;
}

void Mushroom::destroy(){
		live_ = false;
}

void Mushroom::weaken(){
	if(number_of_lives > 0)
		--number_of_lives;
	destroy();
}