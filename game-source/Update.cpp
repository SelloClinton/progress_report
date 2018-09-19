#include "Update.h"

Update::Update()

		{}
void Update::updateGame(shared_ptr<Player>player,Pressed key,shared_ptr<Centipede> centipede,shared_ptr<Field> field){
	updatePlayer(player,key);
	updateCentipede(centipede,field);
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
//void Update::checkBulletSegmentCollision(shared_ptr<Segment> segment, shared_ptr<Bullet> bullet){
//		
//}
//void Update::handleBulletSegmentCollision(shared_ptr<Segment> segment,shared_ptr<Bullet> bullet){
//	
//}
//void Update::checkSegmentPlayerCollision(shared_ptr<Segment> segment){
//		
//}
//void Update::handleSegmentPlayerCollision(shared_ptr<Segment> segment){
//	
//}