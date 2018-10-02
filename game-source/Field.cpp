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
//	createPositions();
	
	auto x_iter = begin(xPositions_);
	auto y_iter = begin(yPositions_);
	while((x_iter != end(xPositions_)&&(y_iter != end(yPositions_)))){
		auto mushroom = make_shared<Mushroom>(*x_iter,*y_iter,EntityID::MUSHROOM);
		mushrooms_.push_back(mushroom);
		x_iter++;
		y_iter++;
		
	}
//	for(auto position_iter = begin(positions_); position_iter != end(positions_); position_iter++){
//			
//			auto mushroom = make_shared<Mushroom>(*position_iter);
//			mushrooms_.push_back(mushroom);
//	}
	
}

void Field::generateXPositions(int numberOfMushrooms){
	

	auto validPosition = 0;
	srand(time(NULL));
	while(validPosition != numberOfMushrooms){
		

			auto random_multiple_of_four = rand() %744+1;
			
			if (auto multiple = 4;random_multiple_of_four% multiple == 0){
					auto x_pos = static_cast<float>(random_multiple_of_four);
					xPositions_.push_back(x_pos);
					validPosition++;
			}
	}
}

void Field::generateYPositions(int numberOfMushrooms){
	
	auto valid_y_positions = 0;
	auto minimum_y_position = 32;
	auto multiple = 4;
	srand(time(NULL));
	while(valid_y_positions != numberOfMushrooms){
		
			auto random_multiple_of_16 = rand() %(static_cast<int>(Constants::DISPLAY_HEIGHT_)-50)+1;
			if ((random_multiple_of_16%multiple == 0)&&(random_multiple_of_16 >=minimum_y_position)){
				auto y_pos = static_cast<float>(random_multiple_of_16);
				yPositions_.push_back(y_pos);
				valid_y_positions++;	
		}
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