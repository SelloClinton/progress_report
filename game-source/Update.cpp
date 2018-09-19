#include "Update.h"

Update::Update()

		{}
void Update::updateGame(shared_ptr<Player>player,Pressed key,shared_ptr<Centipede> centipede,shared_ptr<Field> field){
	updatePlayer(player,key);
	updateCentipede(centipede,field);
	checkBulletSegmentCollision(centipede->getCentipede(),player->getBullets());
	auto field_ = field->getMushrooms(); 
	handleBulletSegmentCollision(centipede->getCentipede(), player->getBullets(), field->getMushrooms());
}

void Update::updatePlayer(shared_ptr<Player> player,Pressed key){
	
	switch(key){
			case Pressed::RIGHT:
				player->attribute()->move(Direction::RIGHT);
				break;
			case Pressed::LEFT:
				player->attribute()->move(Direction::LEFT);
				break;
			case Pressed::SPACE:
				player->shoot();
				break;
		
	}
	player->updateBullet();
}

void Update::updateCentipede(shared_ptr<Centipede> centipede, shared_ptr<Field> field){
	centipede->moveSegments(field);
}
void Update::checkBulletSegmentCollision(list<shared_ptr<Segment>> segments, list<shared_ptr<Bullet>> bullets){
	
	for(auto& segment:segments){
			
		auto[seg_x,seg_y] = segment->attribute()->position()->getPosition();
		for(auto& bullet:bullets){
				auto[bullet_x, bullet_y] = bullet->attribute()->position()->getPosition();
				auto collision_detector = make_shared<CollisionDetection>(seg_x,seg_y,Object::SEGMENT,
																		 bullet_x,bullet_y,Object::BULLET);
				auto status = collision_detector->collided();
				
				if(status){
						segment->attribute()->destroy();
						bullet->attribute()->destroy();
				}
		}
		
	}
		
}
void Update::handleBulletSegmentCollision(list<shared_ptr<Segment>>& segments,list<shared_ptr<Bullet>>& bullets, list<shared_ptr<Mushroom>>& mushrooms){
	auto collision_reactor = make_shared<CollisionReaction>();
	collision_reactor->updateBullets(bullets);
	collision_reactor->updateSegments(segments,mushrooms);
}
//void Update::checkSegmentPlayerCollision(shared_ptr<Segment> segment){
//		
//}
//void Update::handleSegmentPlayerCollision(shared_ptr<Segment> segment){
//	
//}