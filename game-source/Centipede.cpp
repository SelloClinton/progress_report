#include "Centipede.h"


Centipede::Centipede(shared_ptr<Mover> _attribute):
			number_of_segments(5)
{
		createCentipede(_attribute);
}

void Centipede::moveSegments(){
//    get<1>(bullet_->attribute()->position()->getPosition()
        for(auto& segment:centipede_){
//			auto[x_pos,y_pos] = segment->attribute()->position()->getPosition();
            if(auto x_pos = get<0>(segment->attribute()->position()->getPosition()); x_pos < 775){
					segment->attribute()->move(Direction::RIGHT);
            }
        
		}
}

void Centipede::createCentipede(shared_ptr<Mover> _attribute){
	
		auto attr = _attribute;
//		attr->getPosition().setPosition(42,0);
		attr->position()->setPosition(395,0);
		auto head_segment = make_shared<Segment>(attr);
		centipede_.push_back(head_segment);
//		auto separate = 20;
		
		auto position = make_shared<Position>(23,0);
		auto attr2 = make_shared<Mover>(position,2);
//		attr2->getPosition().setPosition(42,150);
		auto head_segment2 = make_shared<Segment>(attr2);
		centipede_.push_back(head_segment2);

//		auto separate = 20;
		
//		for(auto i = 0; i != 2; i++){
//			auto segment_attribute = attribute;
//			segment_attribute->getPosition().setPosition(42+separate,0);
//			auto segment = make_shared<Segment>(segment_attribute);
//			centipede_.push_back(segment);
//		}
		
}

//void Centipede::intializePosition(){
//	
//		
//}