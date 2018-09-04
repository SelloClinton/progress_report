#include "Player.h"

Player::Player(shared_ptr<Mover> attribute):
		attribute_(attribute)
{
	Position bullet_position(400,600);
	auto bullet_attribute = make_shared<Mover>(bullet_position);
	bullet_ = make_shared<Bullet>(bullet_attribute);
			
}
		
shared_ptr<Mover> Player::getAttribute(){
        return attribute_;
}


void Player::shoot(){
	
		bullet_->shoot();
//	while(bullet_->getAttribute()->getPosition().getYPosition() > 0);
		
}

void Player::updateBullet(){
	
		if(bullet_->getAttribute()->getPosition().getYPosition() > 0)
			bullet_->getAttribute()->move(Direction::UP);
		else
			bullet_->destroyBullet();
	
}