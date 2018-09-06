#include "Mover.h"

Mover::Mover(shared_ptr<Position> _position, int speed):
        position_(_position)
        ,speed_(speed)
        {}
        
void Mover::move(Direction direction){
    
	auto[x_position,y_position] = position_->getPosition();
	
    switch(direction){
        case Direction::LEFT:
			if(auto new_x = x_position-getSpeed(); new_x > 0)
				setPosition(new_x,y_position);
            break;
        case Direction::RIGHT:
			if(auto new_x = x_position+getSpeed(); new_x < 785)
				setPosition(new_x,y_position);
            break;
        case Direction::DOWN:
			setPosition(x_position,y_position+getSpeed());
            break;
        case Direction::UP:
            setPosition(x_position,y_position-getSpeed());
            break;
		default:
			assert(false);
    }
    
}
shared_ptr<Position> Mover::position(){
        return position_;
}

void Mover::setPosition(int x, int y){
        position_->setPosition(x,y);
}

int Mover::getSpeed(){
        return speed_;
}