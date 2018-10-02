#include "Update.h"

Update::Update():
		collision_reactor_(make_shared<CollisionReaction>())
		{}
		
void Update::updateGame(shared_ptr<Player>player,Pressed key,shared_ptr<Centipede> centipede,shared_ptr<Field> field){
	updatePlayer(player,key);
	updateCentipede(centipede,field);
	checkLaserSegmentCollision(centipede->getCentipede(),player->getLasers());
	handleLaserSegmentCollision(centipede->getCentipede(), player->getLasers(), field->getMushrooms());
	checkLaserMushroomCollision(player->getLasers(),field->getMushrooms());
	handleLaserMushroomsCollision(player->getLasers(),field->getMushrooms());
	checkSegmentPlayerCollision(centipede->getCentipede(),player);
    checkSegmentMushroomCollision(centipede,field->getMushrooms());
}

void Update::updatePlayer(shared_ptr<Player> player,Pressed key){
	
	switch(key){
		
			case Pressed::RIGHT:
				player->move(Direction::RIGHT);
				break;
			case Pressed::LEFT:
				player->move(Direction::LEFT);
				break;
			case Pressed::UP:
				player->move(Direction::UP);
				break;
			case Pressed::DOWN:
				player->move(Direction::DOWN);
				break;
			case Pressed::SPACE:
				player->shoot();
				break;
		
	}
	player->updateLasers();
}

void Update::updateCentipede(shared_ptr<Centipede> centipede, shared_ptr<Field> field){
	centipede->move();
}
void Update::checkLaserSegmentCollision(list<shared_ptr<Segment>>& segments, list<shared_ptr<Laser>>& lasers){
	
	for(auto& segment:segments){
			
		auto[seg_x,seg_y] = segment->entityAttribute()->position()->getXYPosition();
		for(auto& laser:lasers){
				auto[laser_x, laser_y] = laser->entityAttribute()->position()->getXYPosition();
				auto collision_detector = make_shared<CollisionDetection>(seg_x,seg_y,EntityID::SEGMENT,
																		 laser_x,laser_y,EntityID::LASER);
				auto status = collision_detector->collided();
				
				if(status){
						segment->entityAttribute()->destroy();
						laser->entityAttribute()->destroy();
				}
		}
		
	}
		
}
void Update::handleLaserSegmentCollision(list<shared_ptr<Segment>>& segments,list<shared_ptr<Laser>>& lasers, list<shared_ptr<Mushroom>>& mushrooms){
	collision_reactor_->updateLasers(lasers);
	collision_reactor_->updateSegments(segments,mushrooms);
}
void Update::checkLaserMushroomCollision(list<shared_ptr<Laser>>& lasers,list<shared_ptr<Mushroom>>& mushrooms){
		
	for(auto& laser:lasers){
			auto[laser_x,laser_y] = laser->entityAttribute()->position()->getXYPosition();
			for(auto& mushroom:mushrooms){
					auto[mushroom_x,mushroom_y] = mushroom->entityAttribute()->position()->getXYPosition();
					auto collision_detector = make_shared<CollisionDetection>(laser_x,laser_y,EntityID::LASER,
																				mushroom_x,mushroom_y,EntityID::MUSHROOM);
					auto status = collision_detector->collided();
					if(status){
							laser->entityAttribute()->destroy();
							mushroom->weaken();
					}
			}
	}
}
void Update::handleLaserMushroomsCollision(list<shared_ptr<Laser>>& lasers, list<shared_ptr<Mushroom>>& mushrooms){
	collision_reactor_->updateLasers(lasers);
	collision_reactor_->updateMushrooms(mushrooms);
}
void Update::checkSegmentPlayerCollision(list<shared_ptr<Segment>>& segments, shared_ptr<Player> player){
	
	for(auto& segment:segments){
		auto[seg_x,seg_y] = segment->entityAttribute()->position()->getXYPosition();
		auto[player_x,player_y] = player->entityAttribute()->position()->getXYPosition();
		auto collision_detector = make_shared<CollisionDetection>(seg_x,seg_y,EntityID::SEGMENT,
																		player_x,player_y,EntityID::PLAYER);
		auto status = collision_detector->collided();
		if(status)
			player->entityAttribute()->destroy();
	}	
}

void Update::checkSegmentMushroomCollision(shared_ptr<Centipede>centipede, list<shared_ptr<Mushroom>>& mushrooms){
		
    for(auto& segment:centipede->getCentipede()){
         centipede->handleMushroom(segment,mushrooms);
        }

}
