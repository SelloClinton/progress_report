#include "Mover.h"

Mover::Mover(shared_ptr<Position> _position, int speed):
        position_(_position)
        ,speed_(speed)
		,live_(true)
{
	if (speed <=0)
		throw NegativeZeroSpeed();
}
        
void Mover::move(Direction direction){
    
	auto[x_position,y_position] = position_->getPosition();
	
    switch(direction){
        case Direction::LEFT:
			if(auto new_x = x_position-getSpeed(); !minXBound(new_x))
				setPosition(new_x,y_position);
            break;
        case Direction::RIGHT:
			if(auto new_x = x_position+getSpeed(); !maxXBound(new_x))
				setPosition(new_x,y_position);
            break;
        case Direction::DOWN:
			if(auto new_y = y_position+getSpeed(); !maxYBound(new_y)) 
			setPosition(x_position,new_y);
            break;
        case Direction::UP:
//			if(auto new_y = y_position-getSpeed(); !minXBound(new_y)) 
				setPosition(x_position,y_position-getSpeed());
            break;
		default:
			assert(false);
    }
    
}
shared_ptr<Position> Mover::position(){
        return position_;
}

bool Mover::isLive(){
		return live_;
}
void Mover::setLive(){
		live_ = true;
}
void Mover::destroy(){
		live_ = false;
}

void Mover::setPosition(int x, int y){
        position_->setPosition(x,y);
}

int Mover::getSpeed(){
        return speed_;
}

bool Mover::minXBound(int x_coord){
		if(x_coord < Constants::PLAYER_WIDTH_/2)
			return true;
		return false;
}

bool Mover::maxXBound(int x_coord){
		if(x_coord  >  Constants::DISPLAY_WIDTH_-2*(Constants::PLAYER_WIDTH_))
			return true;
		return false;
}

bool Mover::maxYBound(int y_coord){
		if(y_coord > Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2))
			return true;
		return false;
}