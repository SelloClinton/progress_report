#include "Laser.h"

Laser::Laser(float x_position, float y_position, const EntityID& id, float speed):
		entity_attribute_(make_shared<Entity>(x_position,y_position,id))
		,speed_(speed)
{
	if(speed <= 0)
		throw NegativeZeroLaserSpeed();
	if(id != EntityID::LASER)
		throw IncorrectLaserEntityID();
}
shared_ptr<Entity> Laser::entityAttribute(){
	return entity_attribute_;
}
void Laser:: updatePosition(){
	auto new_y = entity_attribute_->position()->getYPosition()-getSpeed();
	if(auto y_limit = Constants::LASER_HEIGHT_; new_y >= y_limit)
		entity_attribute_->position()->setYPosition(new_y);
	else
		entity_attribute_->destroy();
}

float Laser::getSpeed()const{
	return speed_;
}

//void Laser::move(){
//	auto new_y = entity_attribute_->position()->getYPosition()-getSpeed();
//	if(auto y_limit = Constants::LASER_HEIGHT_; new_ <= y_limit)
//		entity_attribute_->position()->setYPosition(new_y);
//}




//Bullet::Bullet(shared_ptr<Mover> attribute):
//		attribute_(attribute)
//{
//}
//		
//shared_ptr<Mover> Bullet::attribute(){
//        return attribute_;
//}
//
//void Bullet::move(){
//        if(auto y_position = get<1>(attribute()->position()->getPosition()); y_position > Constants::BULLET_HEIGHT_)
//            attribute()->move(Direction::UP);
//        else
//            attribute()->destroy();
//}
//
