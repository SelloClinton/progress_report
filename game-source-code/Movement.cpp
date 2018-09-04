#include "Movement.h"

Movement::Movement():speed_(5)
{}

int Movement::move(Direction direction,int point, int max_border){
	
		if(auto border = 0; ((point>border)&&(point < max_border))){
			
			switch(direction){
					case Direction::LEFT:
					case Direction::DOWN:
						return(point-getSpeed());
						break;
					case Direction::RIGHT:
					case Direction::UP:
						return (point+getSpeed());
						break;
					// default:
						
				
				}
			} 
}

int Movement::getSpeed()const{
		return speed_;
}