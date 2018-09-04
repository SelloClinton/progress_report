#include "Mover.h"

Mover::Mover(Position position):
        position_(position)
        ,speed_(1)
        {}
        
void Mover::move(Direction direction){
    
    switch(direction){
        case Direction::LEFT:
            setPosition((position_.getXPosition()-getSpeed()),position_.getYPosition());
            break;
        case Direction::RIGHT:
            setPosition((position_.getXPosition()+getSpeed()),position_.getYPosition());
            break;
        case Direction::DOWN:
            setPosition((position_.getXPosition()),position_.getYPosition()+getSpeed());
            break;
        case Direction::UP:
            setPosition((position_.getXPosition()),position_.getYPosition()-getSpeed());
            break;
    }
    
}
Position& Mover::getPosition(){
        return position_;
}

void Mover::setPosition(int x, int y){
        position_.setPosition(x,y);
}

int Mover::getSpeed(){
        return speed_;
}