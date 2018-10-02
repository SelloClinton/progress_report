#ifndef COLLISIONREACTION_H
#define COLLISIONREACTION_H

#include "Laser.h"
#include "Segment.h"
#include "Mushroom.h"
#include "Position.h"

#include <list>
#include <memory>
using std::shared_ptr;
using std::make_shared;
using namespace std;


class CollisionReaction{

public:
			CollisionReaction();
			void updateBullets(list<shared_ptr<Bullet>>& bullets);
			void updateSegments(list<shared_ptr<Segment>>& segments, list<shared_ptr<Mushroom>>& mushrooms);
			void updateMushrooms(list<shared_ptr<Mushroom>>& mushrooms);
};
#endif