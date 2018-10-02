#include "Centipede.h"


Centipede::Centipede(int centipedeSize):
			centipede_size_(centipedeSize)
{
        if (centipede_size_ <= 0)
            throw InsufficientCentipedeSize();
        initializePosition();
}

void Centipede::move(){
	
	for(auto& segment:centipede_){
		if(segment->isFacingDown())
			keepDown(segment);
		else if(segment->isFacingUp())
			keepUp(segment);
	}

}
void Centipede::initializePosition(){
	auto y_initial = 0.0f;
    auto separator = 0;
        
    for(auto i = 0; i != centipede_size_; i++){
		
        auto segment_x_position = ((Constants::DISPLAY_WIDTH_/2)-separator*(Constants::PLAYER_WIDTH_));
        auto segment = make_shared<Segment>(segment_x_position,y_initial,EntityID::SEGMENT,Constants::SEGMENT_SPEED_);
        centipede_.push_back(segment);
        separator+=2;
    }
}



void Centipede::moveDown(shared_ptr<Segment>segment){
	auto y_i = segment->entityAttribute()->position()->getYPosition();
	segment->move(Direction::DOWN);
	auto y_f = segment->entityAttribute()->position()->getYPosition();
	if((y_i == y_f)&&(segment->isFacingLeft())){
		segment->faceUp();
		segment->faceRight();
	}
	else if ((y_i == y_f)&&(segment->isFacingRight())){
		segment->faceDown();
		segment->faceRight();
	}
}

void Centipede::moveUp(shared_ptr<Segment> segment){
	auto y_i = segment->entityAttribute()->position()->getYPosition();
	segment->move(Direction::UP);
	auto y_f = segment->entityAttribute()->position()->getYPosition();
	if((y_i == y_f)&&(segment->isFacingLeft())){
		segment->faceDown();
		segment->faceRight();
	}
	else if((y_i == y_f)&&(segment->isFacingRight())){
		segment->faceDown();
		segment->faceLeft();
	}
		
}


void Centipede::turnRight(shared_ptr<Segment>segment){
		segment->move(Direction::RIGHT);
		segment->faceRight();	
}

void Centipede::turnLeft(shared_ptr<Segment>segment){
		segment->move(Direction::LEFT);
		segment->faceLeft();	
}

void Centipede::handleMushroom(shared_ptr<Segment> segment, list<shared_ptr<Mushroom>> mushrooms){
	
		auto[seg_x,seg_y] = segment->entityAttribute()->position()->getXYPosition();
		for(auto& mushroom:mushrooms){
				auto[mush_x,mush_y] = mushroom->entityAttribute()->position()->getXYPosition();
				auto collision_detector = make_shared<CollisionDetection>(seg_x,seg_y,EntityID::SEGMENT,
																		  mush_x,mush_y,EntityID::MUSHROOM);
				auto status = collision_detector->collided();
				
				if((status)&&(segment->isFacingLeft())&&(segment->isFacingDown())){
					moveDown(segment);
					turnRight(segment);
				}
				
				else if((status)&&(segment->isFacingRight())&&(segment->isFacingDown())){
					moveDown(segment);
					turnLeft(segment);
				}
				else if((status)&&(segment->isFacingLeft())&&(segment->isFacingUp())){
					moveUp(segment);
					turnRight(segment);
				}
				else if((status)&&(segment->isFacingRight())&&(segment->isFacingUp())){
					moveUp(segment);
					turnLeft(segment);
				}
				
		}
}
void Centipede::keepUp(shared_ptr<Segment> segment){
	
	auto[seg_x_position,seg_y_position] = segment->entityAttribute()->position()->getXYPosition();
	cout << seg_y_position << endl;
	if(!segment->isFacingDown()){
		
        if(seg_x_position >= 774){
			moveUp(segment);
			turnLeft(segment);
        }
        else if (seg_x_position <= 4){
			moveUp(segment);
			turnRight(segment);
        }
        else if (segment->isFacingLeft()){
			segment->move(Direction::LEFT);
        }
        else
            segment->move(Direction::RIGHT);				
		
	}
	else
		segment->faceDown();	
	
		
}

void Centipede::keepDown(shared_ptr<Segment> segment){
	
	auto[seg_x_position,seg_y_position] = segment->entityAttribute()->position()->getXYPosition();
	
	if(!segment->isFacingUp()){
		
        if(seg_x_position >= 774){
			moveDown(segment);
			turnLeft(segment);
        }
        else if (seg_x_position <= 4){
			moveDown(segment);
			turnRight(segment);
        }
        else if (segment->isFacingLeft()){
			segment->move(Direction::LEFT);
        }
        else
            segment->move(Direction::RIGHT);
		
	}
	else 
		segment->faceUp();
	
		
}