#include "Centipede.h"


Centipede::Centipede(int centipedeSize):
			centipede_size_(centipedeSize)
{
        if (centipede_size_ <= 0)
            throw InsufficientCentipedeSize();
        initializePosition();
}

void Centipede::moveSegments(shared_ptr<Field> field){
	
	for(auto& segment:centipede_){
		  auto[segx,segy] = segment->attribute()->position()->getPosition();
		  auto mushrooms = field->getMushrooms();
		  
		  handleMushroom(segment,mushrooms);
		

		auto x_position = get<0>(segment->attribute()->position()->getPosition()); 
        if(x_position >= 774){
			moveDown(segment);
			turnLeft(segment);
        }
        else if (x_position <= 4){
			moveDown(segment);
			turnRight(segment);
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

void Centipede::moveUp(shared_ptr<Segment> segment){
		segment->attribute()->move(Direction::UP);
		segment->attribute()->move(Direction::UP);
		segment->attribute()->move(Direction::UP);
		segment->attribute()->move(Direction::UP);
}


void Centipede::turnRight(shared_ptr<Segment>segment){
		segment->attribute()->move(Direction::RIGHT);
		segment->faceRight();	
}

void Centipede::turnLeft(shared_ptr<Segment>segment){
		segment->attribute()->move(Direction::LEFT);
		segment->faceLeft();	
}
void Centipede::keepUp(shared_ptr<Segment> segment){
		
}

void Centipede::handleMushroom(shared_ptr<Segment> segment, list<shared_ptr<Mushroom>> mushrooms){
	
		auto[seg_x,seg_y] = segment->attribute()->position()->getPosition();
		for(auto& mushroom:mushrooms){
				auto[mush_x,mush_y] = mushroom->position()->getPosition();
				auto collision_detector = make_shared<CollisionDetection>(seg_x,seg_y,Object::SEGMENT,
																		  mush_x,mush_y,Object::MUSHROOM);
				auto status = collision_detector->collided();
				
				if((status)&&(segment->isFacingLeft())){
					moveDown(segment);
					turnRight(segment);
				}
				
				else if((status)&&(segment->isFacingRight())){
					moveDown(segment);
					turnLeft(segment);
				}
				
		}
}