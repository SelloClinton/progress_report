#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Position.h"
#include "Entity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Mushroom{

public:	
	Mushroom(float x_position, float y_position, const EntityID& id);
	shared_ptr<Entity>entityAttribute();
	void weaken();
private:
	shared_ptr<Entity> entity_attribute_;
	int number_of_lives;
};
#endif