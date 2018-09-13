#include "Field.h"

Field::Field(int numberOfMushrooms)
{
	
	createMushrooms(numberOfMushrooms);
	
}

Mushrooms& Field::getMushrooms(){
		return mushrooms_;
}

void Field::createMushrooms(int numberOfMushrooms){
	generateXPositions(numberOfMushrooms);
	generateYPositions(numberOfMushrooms);
	createPositions();
	
	
	for(auto position_iter = begin(positions_); position_iter != end(positions_); position_iter++){
			
			auto mushroom = make_shared<Mushroom>(*position_iter);
			mushrooms_.push_back(mushroom);
	}
	
}

void Field::generateXPositions(int numberOfMushrooms){
	

	auto validPosition = 0;
	srand(time(NULL));
	while(validPosition != numberOfMushrooms){
		

			auto random_multiple_of_four = rand() %744+1;
			
			if (random_multiple_of_four%4 == 0){
					xPositions_.push_back(random_multiple_of_four);
					validPosition++;
			}
	}
}

void Field::generateYPositions(int numberOfMushrooms){
	
	//corresponding multiples are yet to be discovered
	srand(time(NULL));
	for(auto i = 0; i != numberOfMushrooms; i++){

		auto random_multiple_of_four = rand() %(Constants::DISPLAY_HEIGHT_-50)+1;
		yPositions_.push_back(random_multiple_of_four);
	}
}

void Field::createPositions(){
		
	
		auto x_iter =  begin(xPositions_);
		auto y_iter = begin(yPositions_);
		
		while((x_iter != end(xPositions_)&&(y_iter != end(yPositions_)))){
			auto x_position = *x_iter;
			auto y_position = *y_iter;
			auto position = make_shared<Position>(x_position,y_position);
			positions_.push_back(position);
			x_iter++;
			y_iter++;
		}
}