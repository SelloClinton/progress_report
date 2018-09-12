#include "Field.h"

Field::Field(int numberOfMushrooms)
{
	
	createMushrooms(numberOfMushrooms);
	
}

Mushrooms& Field::getMushrooms(){
		return mushrooms_;
}

void Field::createMushrooms(int numberOfMushrooms){		//this causes some delay while loading...why?!
	generateXPositions(numberOfMushrooms);
	generateYPositions(numberOfMushrooms);
//	createPositions();
	
		auto x_iter =  begin(xPositions_);
		auto y_iter = begin(yPositions_);
		
		while((x_iter != end(xPositions_))&&(y_iter != end(yPositions_))){
			auto x_position = *x_iter;
			auto y_position = *y_iter;
			auto position = make_shared<Position>(x_position,y_position);
			auto mushroom = make_shared<Mushroom>(position);
			mushrooms_.push_back(mushroom);
			x_iter++;
			y_iter++;
		}
	
//	for(auto position_iter = begin(positions_); position_iter != end(positions_); position_iter++){
//			
//			auto mushroom = make_shared<Mushroom>(*position_iter);
//			mushrooms_.push_back(mushroom);
//	}
	
//	cout << "Mushrooms size : " << mushrooms_.size() << endl;
}

void Field::generateXPositions(int numberOfMushrooms){
	

	auto validPosition = 0;
	
	while(validPosition != numberOfMushrooms){
			srand(time(NULL));
			auto random_multiple_of_four = rand() %744+1;
			
			if (random_multiple_of_four%4 == 0){
					xPositions_.push_back(random_multiple_of_four);
					validPosition++;
			}
				
	}
//	cout << "xPositions size : " << xPositions_.size() << endl;
}

void Field::generateYPositions(int numberOfMushrooms){
	
	//corresponding multiples are yet to be discovered

	
	for(auto i = 0; i != numberOfMushrooms; i++){
		srand(time(NULL));
		auto random_multiple_of_four = rand() %(Constants::DISPLAY_HEIGHT_-50)+1;
		yPositions_.push_back(random_multiple_of_four);
	}
//	cout << "Ypositions size: " << yPositions_.size() << endl;
}

void Field::createPositions(){
		
	
		auto x_iter =  begin(xPositions_);
		auto y_iter = begin(yPositions_);
		
		while(x_iter != end(xPositions_)){
			auto x_position = *x_iter;
			auto y_position = *y_iter;
			auto position = make_shared<Position>(x_position,y_position);
			x_iter++;
			y_iter++;
		}
	
//	for(auto x_iter = begin(xPositions_), y_iter = begin(yPositions_); x_iter != end(xPositions_), y_iter != end(yPositions_); x_iter++,y_iter++){
//		
//			auto x_position = *x_iter;
//			auto y_position = *y_iter;
//			auto position = make_shared<Position>(x_position,y_position);
//			positions_.push_back(position);
//			x_iter++;
//			y_iter++;
//	}
}