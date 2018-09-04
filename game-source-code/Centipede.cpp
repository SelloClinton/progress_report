#include "Centipede.h"

Centipede::Centipede(shared_ptr<Mover> attribute)
{
        auto attr = attribute;
        Segment head(attr);
        head.getAttribute()->getPosition().setPosition(20,0);
        centipede_.push_back(head);
        Segment tail(attr);
        tail.getAttribute()->getPosition().setPosition(3,0);
        centipede_.push_back(tail);
}

void Centipede::moveSegments(){
    
        auto count = 0;
        bool left = false;
        bool right = true;
        
        for(auto& segment:centipede_){
            if(segment.getAttribute()->getPosition().getXPosition() > 775){
                right = false;
                left = true;
            }
            if(segment.getAttribute()->getPosition().getXPosition() == 0){
                right = true;
                left = false;
            }
            
            if((right))
                segment.getAttribute()->move(Direction::RIGHT);
            else
                segment.getAttribute()->move(Direction::LEFT);
        }
        
}