#include "Player.h"

Player::Player(shared_ptr<Mover> attribute):
		attribute_(attribute)
{
			
}
		
shared_ptr<Mover> Player::attribute(){
        return attribute_;
}

void Player::moveUp(){
		if(get<1>(attribute_->position()->getPosition()) > Constants::PLAYER_VERTICAL_LIMIT)
			attribute_->move(Direction::UP);
}
void Player::shoot(){
    auto[x_position,y_position] = attribute_->position()->getPosition();
    auto bullet_position = make_shared<Position>(x_position+(Constants::PLAYER_WIDTH_),y_position-(Constants::PLAYER_HEIGHT_));
    auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
    auto bullet = make_shared<Bullet>(bullet_mover);
    bullets_.push_back(bullet);
}

void Player::updateBullet(){
	
    for(auto& bullet:bullets_){
        bullet->move();
    }
}