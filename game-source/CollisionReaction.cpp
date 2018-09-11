#include "CollisionReaction.h"

CollisionReaction::CollisionReaction()
{}

void CollisionReaction::updateBullets(list<shared_ptr<Bullet>> bullets){
	
	for(auto iter = begin(bullets); iter != end(bullets); iter++){
	
		if (!(iter->isShot()))
			iter = bullets.erase(iter);
	}
}

//void CollisionReaction::updateSegments(list<shared_ptr<Segment>> segments){
//	
//	
//}