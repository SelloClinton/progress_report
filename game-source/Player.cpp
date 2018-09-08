#include "Player.h"

Player::Player(shared_ptr<Mover> attribute):
		attribute_(attribute)
{
//	auto bullet_position = make_shared<Position>(400,600);
//	auto bullet_speed = 3;
//	auto bullet_attribute = make_shared<Mover>(bullet_position,bullet_speed);
//	bullet_ = make_shared<Bullet>(bullet_attribute);
			
}
		
shared_ptr<Mover> Player::attribute(){
        return attribute_;
}


void Player::shoot(){
    auto[x_position,y_position] = attribute_->position()->getPosition();
    auto bullet_position = make_shared<Position>(x_position,y_position);
    auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
    auto bullet = make_shared<Bullet>(bullet_mover);
	bullet->shoot();	
    bullets_.push_back(bullet);
}

void Player::updateBullet(){
	
    for(auto& bullet:bullets_){
//        if(auto bullet_y_position = get<1>(bullet->attribute()->position()->getPosition()); bullet_y_position > 0)
            bullet->attribute()->move(Direction::UP);
    }
//		auto[bullet_x_position,bullet_y_position] = bullet_->attribute()->position()->getPosition();

//		if(auto bullet_y_position = get<1>(bullet_->attribute()->position()->getPosition()); bullet_y_position > 0)
//			bullet_->attribute()->move(Direction::UP);
//		else
//			bullet_->destroyBullet();
	
}