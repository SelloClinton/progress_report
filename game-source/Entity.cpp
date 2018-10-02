#include "Entity.h"

Entity::Entity(float x, float y, const EntityID& id):
		position_(make_shared<Position>(x,y))
		,id_(id)
		,live_(true)
		{}
shared_ptr<Position> Entity::position(){
	return position_;
}
bool Entity::isLive()const{
	return live_;
}
void Entity::destroy(){
	live_ = false;
}
const EntityID& Entity::getEntityID()const{
	return id_;
}


