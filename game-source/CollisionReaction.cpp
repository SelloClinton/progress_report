#include "CollisionReaction.h"

CollisionReaction::CollisionReaction()
{}

void CollisionReaction::updateBullets(list<shared_ptr<Bullet>>& bullets){
	
	for(auto bullets_iterator = begin(bullets); bullets_iterator != end(bullets); bullets_iterator++){
	
		if (!((*bullets_iterator)->isShot()))
			bullets_iterator = bullets.erase(bullets_iterator);
	}
}

void CollisionReaction::updateSegments(list<shared_ptr<Segment>>& segments){

	for(auto segments_iterator = begin(segments); segments_iterator != end(segments); segments_iterator++){
	
		if (!((*segments_iterator)->isLive()))
			segments_iterator = segments.erase(segments_iterator);
	}	
	
}