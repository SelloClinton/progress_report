#include "Segment.h"

Segment::Segment(float x_position, float y_position,const EntityID& id, float speed):
		entity_attribute_(make_shared<Entity>(x_position,y_position,id))
        ,right_flag_(true)
        ,left_flag_(false)
		,down_flag_(true)
		,up_flag_(false)
{
	if (id != EntityID::SEGMENT)
		throw InvalidSegmentEntityID();
	if (speed != Constants::SEGMENT_SPEED_)
		throw InvalidSegmentSpeed();
}
		
shared_ptr<Entity> Segment::entityAttribute(){
        return entity_attribute_;
}
void Segment::move(Direction direction){
	auto[x,y] = entity_attribute_->position()->getXYPosition();
	auto mover = make_shared<Mover>(x,y,Constants::SEGMENT_SPEED_);
	
	switch(direction){
		case Direction::RIGHT:
			mover->moveRight();
			entity_attribute_->position()->setXPosition(get<0>(mover->position()));
			break;
		case Direction::LEFT:
			mover->moveLeft();
			entity_attribute_->position()->setXPosition(get<0>(mover->position()));
			break;
		case Direction::UP:
			mover->moveUp();
			mover->moveUp();
			mover->moveUp();
			mover->moveUp();
			entity_attribute_->position()->setYPosition(get<1>(mover->position()));
			break;
		case Direction::DOWN:
			mover->moveDown();
			mover->moveDown();
			mover->moveDown();
			mover->moveDown();
			entity_attribute_->position()->setYPosition(get<1>(mover->position()));
			break;
		default:
			assert(false);
	}
}
void Segment::faceLeft(){
        right_flag_ = false;
        left_flag_ = true;
}
void Segment::faceRight(){
    right_flag_ = true;
    left_flag_ = false;
}
void Segment::faceDown(){
	down_flag_ = true;
	up_flag_ = false;
}
void Segment::faceUp(){
	down_flag_ = false;
	up_flag_ = true;
}
bool Segment::isFacingLeft(){
    if((!right_flag_)&&(left_flag_))
        return true;
    return false;
}
bool Segment::isFacingRight(){
    if((right_flag_)&&(!left_flag_))
        return true;
    return false;
}
bool Segment::isFacingDown(){
	if ((down_flag_)&&(!up_flag_))
		return true;
	return false;
}
bool Segment::isFacingUp(){
	if ((up_flag_)&&(!down_flag_))
		return true;
	return false;
}
