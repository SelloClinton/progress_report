#include "CollisionReaction.h"

CollisionReaction::CollisionReaction()
{}

void CollisionReaction::updateLasers(list<shared_ptr<Laser>>& lasers){
	
	for(auto lasers_iterator = begin(lasers); lasers_iterator != end(lasers); lasers_iterator++){
	
		if (!((*lasers_iterator)->entityAttribute()->isLive()))
			lasers_iterator = lasers.erase(lasers_iterator);
	}
}

void CollisionReaction::updateSegments(list<shared_ptr<Segment>>& segments, list<shared_ptr<Mushroom>>& field){

	for(auto segments_iterator = begin(segments); segments_iterator != end(segments); segments_iterator++){
	
		if (!((*segments_iterator)->entityAttribute()->isLive())){
			auto[mush_x,mush_y] = (*segments_iterator)->entityAttribute()->position()->getXYPosition();
//			auto mush_position = make_shared<Position>(mush_x,mush_y);
			auto mushroom = make_shared<Mushroom>(mush_x,mush_y,EntityID::MUSHROOM);
			field.push_back(mushroom);
			segments_iterator = segments.erase(segments_iterator);
			
		}
	}
}	
	


void CollisionReaction::updateMushrooms(list<shared_ptr<Mushroom>>& mushrooms){
	
		for(auto mushroom_iterator = begin(mushrooms); mushroom_iterator != end(mushrooms); mushroom_iterator++){
			
			if (!((*mushroom_iterator)->entityAttribute()->isLive()))
				mushroom_iterator = mushrooms.erase(mushroom_iterator);
		}
}