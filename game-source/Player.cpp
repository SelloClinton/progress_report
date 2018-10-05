#include "Player.h"

Player::Player(float x_position, float y_position, const EntityID& id, float speed):
		entity_attribute_(make_shared<Entity>(x_position,y_position,id))

{
	if (speed != Constants::PLAYER_SPEED_)
		throw IncorrectPlayerSpeed();
	if (id != EntityID::PLAYER)
		throw IncorrectPlayerEntityID();
	if (y_position < Constants::PLAYER_VERTICAL_LIMIT)
		throw IncorrectPlayerPosition();
}

shared_ptr<Entity> Player::entityAttribute(){
	return entity_attribute_;
}
void Player::move(Direction direction){
	
	auto[x,y] = entity_attribute_->position()->getXYPosition();
	auto mover = make_shared<Mover>(x,y,Constants::PLAYER_SPEED_);
	
	switch(direction){
		case Direction::RIGHT:
			mover->moveRight();
			entity_attribute_->position()->setXPosition(get<0>(mover->position()));
			break;
		case Direction::LEFT:
			mover->moveLeft();
			entity_attribute_->position()->setXPosition(get<0>(mover->position()));
			break;
		case Direction::UP:
			mover->moveUp();
			entity_attribute_->position()->setYPosition(get<1>(mover->position()));
			break;
		case Direction::DOWN:
			mover->moveDown();
			entity_attribute_->position()->setYPosition(get<1>(mover->position()));
			break;
		default:
			assert(false);
	}
	

	
}
void Player::shoot(){
		
//		if(auto max_lasers = 4; lasers_.size() <= max_lasers){
			auto[x,y] = entity_attribute_->position()->getXYPosition();
			auto laser_x = x+(Constants::PLAYER_WIDTH_);
			auto laser_y = y-(Constants::PLAYER_HEIGHT_);
			auto laser = make_shared<Laser>(laser_x,laser_y,EntityID::LASER,Constants::LASER_SPEED_);
			lasers_.push_back(laser);
//		}
}
Lasers& Player::getLasers(){
	return lasers_;
}
void Player::updateLasers(){
	for(auto& laser:lasers_)
		laser->updatePosition();
}
//
//void Player::shoot(){
//	
//	if(bullets_.size() <= 4){
//		auto[x_position,y_position] = attribute_->position()->getPosition();
//		auto bullet_position = make_shared<Position>(x_position+(Constants::PLAYER_WIDTH_),y_position-(Constants::PLAYER_HEIGHT_));
//		auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
//		auto bullet = make_shared<Bullet>(bullet_mover);
//		bullets_.push_back(bullet);
//	
//	}
//	
//}
//
//void Player::updateBullet(){
//	
//    for(auto& bullet:bullets_){
//        bullet->move();
//    }
//}