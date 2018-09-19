#include "Segment.h"

Segment::Segment(shared_ptr<Mover> attribute):
		attribute_(attribute)
        ,right_flag_(true)
        ,left_flag_(false)
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

//bool Segment::isLive(){
//		return live;
//}
//
//void Segment::destroySegment(){
//		live = false;
//}