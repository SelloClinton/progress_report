#ifndef LASER_H
#define LASER_H

#include "Entity.h"
#include "Constants.h"
#include "Enums.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

class IncorrectLaserSpeed{};
class IncorrectLaserEntityID{};

class Laser{
	
public:
	Laser(float x_position, float y_position, const EntityID& id, float speed);
	shared_ptr<Entity> entityAttribute();
	void updatePosition();
private:
	shared_ptr<Entity> entity_attribute_;
	float speed_;
	float getSpeed()const;
};

#endif