#include "CollisionReaction.h"

CollisionReaction::CollisionReaction()
{}

void CollisionReaction::updateBullets(list<shared_ptr<Bullet>>& bullets){
	
	for(auto bullets_iterator = begin(bullets); bullets_iterator != end(bullets); bullets_iterator++){
	
		if (!((*bullets_iterator)->attribute()->isLive()))
			bullets_iterator = bullets.erase(bullets_iterator);
	}
}

void CollisionReaction::updateSegments(list<shared_ptr<Segment>>& segments, list<shared_ptr<Mushroom>>& field){

	for(auto segments_iterator = begin(segments); segments_iterator != end(segments); segments_iterator++){
	
		if (!((*segments_iterator)->attribute()->isLive())){
			auto[mush_x,mush_y] = (*segments_iterator)->attribute()->position()->getPosition();
			auto mush_position = make_shared<Position>(mush_x,mush_y);
			auto mushroom = make_shared<Mushroom>(mush_position);
			field.push_back(mushroom);
			segments_iterator = segments.erase(segments_iterator);
			
		}
	}
}	
	


void CollisionReaction::updateMushrooms(list<shared_ptr<Mushroom>>& mushrooms){
	
		for(auto mushroom_iterator = begin(mushrooms); mushroom_iterator != end(mushrooms); mushroom_iterator++){
			
			if (!((*mushroom_iterator)->isLive()))
				mushroom_iterator = mushrooms.erase(mushroom_iterator);
		}
}