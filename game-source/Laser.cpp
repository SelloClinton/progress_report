#include "Laser.h"

Laser::Laser(float x_position, float y_position, const EntityID& id, float speed):
		entity_attribute_(make_shared<Entity>(x_position,y_position,id))
		,speed_(speed)
{
	if(speed != Constants::LASER_SPEED_)
		throw IncorrectLaserSpeed();
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

