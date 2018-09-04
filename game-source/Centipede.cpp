#include "Centipede.h"


Centipede::Centipede(shared_ptr<Mover> attribute):number_of_segments(5)
{
		createCentipede(attribute);
}

void Centipede::moveSegments(){
    
        for(auto& segment:centipede_){
            if(segment->getAttribute()->getPosition().getXPosition() < 775){
					segment->getAttribute()->move(Direction::RIGHT);
            }
        
		}
}

void Centipede::createCentipede(shared_ptr<Mover> attribute){
	
		auto attr = attribute;
		attr->getPosition().setPosition(42,0);
		auto head_segment = make_shared<Segment>(attr);
		centipede_.push_back(head_segment);
		auto separate = 20;
		
		Position position(23,0);
		auto attr2 = make_shared<Mover>(position);
//		attr2->getPosition().setPosition(42,150);
		auto head_segment2 = make_shared<Segment>(attr2);
		centipede_.push_back(head_segment2);
		std::cout << centipede_.size() << std::endl;
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