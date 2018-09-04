#include "Position.h"

Position::Position(int x_position, int y_position):
		  x_position_(x_position),
		  y_position_(y_position)
		  {}
tuple<int,int> Position::getPosition()const{
		return{getXPosition(),getYPosition()};
}

void Position::setPosition(int x, int y){
		x_position_ = x;
		y_position_ = y;
}

int Position::getXPosition()const{
		return x_position_;
}

int Position::getYPosition()const{
		return y_position_;
}

void Position::setXPosition(int x_pos){
		x_position_ = x_pos;
}

void Position::setYPosition(int y_pos){
		y_position_ = y_pos;
}