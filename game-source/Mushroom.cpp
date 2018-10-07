#include "Mushroom.h"

Mushroom::Mushroom(float x_position, float y_position, const EntityID& id):
		  entity_attribute_(make_shared<Entity>(x_position,y_position,id))
		  ,number_of_lives(4)
{
	if (id != EntityID::MUSHROOM)
			throw IncorrectMushroomEntityID();
}
		  
shared_ptr<Entity> Mushroom::entityAttribute(){
	return entity_attribute_;
}

void Mushroom::weaken(){
	if(number_of_lives > 1)
		--number_of_lives;
	else
		entity_attribute_->destroy();
}