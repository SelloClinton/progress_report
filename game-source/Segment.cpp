#include "Segment.h"

Segment::Segment(shared_ptr<Mover> attribute):
		attribute_(attribute)
        ,right_flag_(true)
        ,left_flag_(false)
		,down_flag_(true)
		,up_flag_(false)
{
	attribute_->setLive();
}
		
shared_ptr<Mover> Segment::attribute(){
        return attribute_;
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
bool Segment::isMovingDown(){
	if ((down_flag_)&&(!up_flag_))
		return true;
	return false;
}
bool Segment::isMovingUp(){
	if ((up_flag_)&&(!down_flag_))
		return true;
	return false;
}
