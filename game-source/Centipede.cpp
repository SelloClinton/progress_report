#include "Centipede.h"

Centipede::Centipede(shared_ptr<Mover> attribute)
{
//        auto attr = attribute;
//        Segment head(attr);
//        head.getAttribute()->getPosition().setPosition(20,0);
//        centipede_.push_back(head);
//        Segment tail(attr);
//        tail.getAttribute()->getPosition().setPosition(3,0);
//        centipede_.push_back(tail);
		createCentipede(attribute);
}

void Centipede::moveSegments(){
    

        
        for(auto& segment:centipede_){
            if(segment->getAttribute()->getPosition().getXPosition() > 775){
					segment->getAttribute()->move(Direction::RIGHT);
            }
		}
//            if(segment.getAttribute()->getPosition().getXPosition() == 0){
//                right = true;
//                left = false;
//            }
//            
//            if((right))
//                segment.getAttribute()->move(Direction::RIGHT);
//            else
//                segment.getAttribute()->move(Direction::LEFT);
//        }
        
}

void Centipede::createCentipede(shared_ptr<Mover> attribute){
	
		auto attr = attribute;
		attr->getPosition().setPosition(42,0);
		auto head_segment = make_shared<Segment>(attr);
		centipede_.push_back(head_segment);
		auto separate = 7;
		
		for(auto i = 0; i != 5; i++){
			auto segment_attribute = attribute;
			segment_attribute->getPosition().setPosition(42+separate,0);
			auto segment = make_shared<Segment>(segment_attribute);
			centipede_.push_back(segment);
		}
}