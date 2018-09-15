#include "Update.h"

Update::Update(shared_ptr<Player> player,shared_ptr<Centipede>centipede,shared_ptr<Field> field):
		player_(player)
		,centipede_(centipede)
		{}
void Update::updateGame(){
	
}

void Update::updatePlayer(){
	
}

void Update::updateCentipede(shared_ptr<Field> field){
	
}
void Update::checkBulletSegmentCollision(shared_ptr<Segment> segment, shared_ptr<Bullet> bullet){
		
}
void Update::handleBulletSegmentCollision(shared_ptr<Segment> segment,shared_ptr<Bullet> bullet){
	
}
void Update::checkSegmentPlayerCollision(shared_ptr<Segment> segment){
		
}
void Update::handleSegmentPlayerCollision(shared_ptr<Segment> segment){
	
}