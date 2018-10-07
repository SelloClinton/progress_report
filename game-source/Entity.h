#ifndef ENTITY_H
#define ENTITY_H

#include "Position.h"
#include "Enums.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Entity{
public:
		Entity(float x, float y, const EntityID& id);
		shared_ptr<Position> position();
		bool isLive()const;
		void destroy();
		const EntityID& getEntityID()const;
private:
		shared_ptr<Position> position_;
		EntityID id_;
		bool live_;
};
#endif