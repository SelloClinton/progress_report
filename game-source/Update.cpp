#include "Update.h"

Update::Update()

		{}
void Update::updateGame(shared_ptr<Player>player,Pressed key,shared_ptr<Centipede> centipede,shared_ptr<Field> field){
	updatePlayer(player,key);
	updateCentipede(centipede,field);
	checkBulletSegmentCollision(centipede->getCentipede(),player->getBullets());
	handleBulletSegmentCollision(centipede->getCentipede(), player->getBullets(), field->getMushrooms());
	checkBulletMushroomCollision(player->getBullets(),field->getMushrooms());
	handleBulletMushroomsCollision(player->getBullets(),field->getMushrooms());
	checkSegmentPlayerCollision(centipede->getCentipede(),player);
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
void Update::checkBulletMushroomCollision(list<shared_ptr<Bullet>> bullets,list<shared_ptr<Mushroom>> mushrooms){
		
	for(auto& bullet:bullets){
			auto[bullet_x,bullet_y] = bullet->attribute()->position()->getPosition();
			for(auto& mushroom:mushrooms){
					auto[mushroom_x,mushroom_y] = mushroom->position()->getPosition();
					auto collision_detector = make_shared<CollisionDetection>(bullet_x,bullet_y,Object::BULLET,
																				mushroom_x,mushroom_y,Object::MUSHROOM);
					auto status = collision_detector->collided();
					if(status){
							bullet->attribute()->destroy();
							mushroom->weaken();
					}
			}
	}
}
void Update::handleBulletMushroomsCollision(list<shared_ptr<Bullet>>& bullets, list<shared_ptr<Mushroom>>& mushrooms){
	auto collision_reactor = make_shared<CollisionReaction>();
	collision_reactor->updateBullets(bullets);
	collision_reactor->updateMushrooms(mushrooms);
}
void Update::checkSegmentPlayerCollision(list<shared_ptr<Segment>> segments, shared_ptr<Player> player){
	
	for(auto& segment:segments){
			auto[seg_x,seg_y] = segment->attribute()->position()->getPosition();
			auto[player_x,player_y] = player->attribute()->position()->getPosition();
			auto collision_detector = make_shared<CollisionDetection>(seg_x,seg_y,Object::SEGMENT,
																		player_x,player_y,Object::PLAYER);
			auto status = collision_detector->collided();
			if(status)
				player->attribute()->destroy();
	}	
}
//void Update::handleSegmentPlayerCollision(shared_ptr<Segment> segment){
//	
//}