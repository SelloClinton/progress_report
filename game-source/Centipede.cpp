#include "Centipede.h"


Centipede::Centipede(int centipedeSize):
			centipede_size_(centipedeSize)
{
        if (centipede_size_ <= 0)
            throw InsufficientCentipedeSize{};
        initializePosition();
}

void Centipede::moveSegments(){
    
       for(auto& segment:centipede_){
		auto x_position = get<0>(segment->attribute()->position()->getPosition()); 
        if(x_position >= 774){
			turnLeft(segment);
        }
        else if (x_position <= 8){
			turnLeft(segment);
        }
        else if (segment->isFacingLeft()){
			segment->attribute()->move(Direction::LEFT);
        }
        else
            segment->attribute()->move(Direction::RIGHT);
		}
}
void Centipede::initializePosition(){ 
    auto separator = 0;
        
    for(auto i = 0; i != centipede_size_; i++){
		
        auto segment_x_position = (Constants::DISPLAY_WIDTH_/2)-separator*(Constants::PLAYER_WIDTH_);
        auto position = make_shared<Position>(segment_x_position,0);
        auto mover = make_shared<Mover>(position,Constants::SEGMENT_SPEED_);
        auto segment = make_shared<Segment>(mover);
        centipede_.push_back(segment);
        separator+=2;
    }
}

void Centipede::moveDown(shared_ptr<Segment>segment){
	
		segment->attribute()->move(Direction::DOWN);
		segment->attribute()->move(Direction::DOWN);
		segment->attribute()->move(Direction::DOWN);
		segment->attribute()->move(Direction::DOWN);	
}


void Centipede::turnRight(shared_ptr<Segment>segment){
		moveDown(segment);
		segment->attribute()->move(Direction::RIGHT);
		segment->faceRight();	
}

void Centipede::turnLeft(shared_ptr<Segment>segment){
		moveDown(segment);
		segment->attribute()->move(Direction::LEFT);
		segment->faceLeft();	
}