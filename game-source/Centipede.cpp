#include "Centipede.h"


Centipede::Centipede(int centipedeSize):
			centipede_size_{centipedeSize}
            ,rightFlag_(true)
            ,leftFlag_(false)
{
        if (centipede_size_ < 0)
            throw InsufficientCentipedeSize{};
        initializePosition();
}

void Centipede::moveSegments(){
    
       for(auto& segment:centipede_){
            auto x_position = get<0>(segment->attribute()->position()->getPosition());
            
            if (x_position == 775){    //||(segment->attribute()->maxXBound(x_position))){
                segment->attribute()->move(Direction::DOWN);
                segment->attribute()->move(Direction::DOWN);
                segment->attribute()->move(Direction::DOWN);
                segment->attribute()->move(Direction::LEFT);
                segment->attribute()->move(Direction::LEFT);
                faceLeft(segment);
            }
            else if (x_position == 7){
                segment->attribute()->move(Direction::DOWN);
                segment->attribute()->move(Direction::DOWN);
                segment->attribute()->move(Direction::DOWN);
                segment->attribute()->move(Direction::RIGHT);
                faceRight(segment);
            }

            else if (isFacingLeft(segment,x_position)){
                segment->attribute()->move(Direction::LEFT);
            }
            else// (isFacingRight(segment,x_position))
            {
                segment->attribute()->move(Direction::RIGHT);
            }


//            if(auto x_pos = get<0>(segment->attribute()->position()->getPosition()); x_pos < 775){
//					segment->attribute()->move(Direction::RIGHT);
//            }
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

void Centipede::faceRight(shared_ptr<Segment>segment){
    rightFlag_ = true;
    leftFlag_ = false;
}
void Centipede::faceLeft(shared_ptr<Segment>segment){
        rightFlag_ = false;
        leftFlag_ = true;
}
bool Centipede::isFacingLeft(shared_ptr<Segment>segment, int x_position){
        if (((!segment->attribute()->minXBound(x_position))||
            (!segment->attribute()->maxXBound(x_position)))
            &&(leftFlag_)&&(!rightFlag_)
            )
                return true;
        else
            return false;
}
bool Centipede::isFacingRight(shared_ptr<Segment>segment, int x_position){
        if (((!segment->attribute()->minXBound(x_position))||
            (!segment->attribute()->maxXBound(x_position)))
            &&(rightFlag_)&&(!leftFlag_)
            )
                return true;
        else
            return false;
                
}

