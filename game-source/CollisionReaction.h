#ifndef COLLISIONREACTION_H
#define COLLISIONREACTION_H

#include "Bullet.h"
#include "Segment.h"

#include <list>
#include <memory>
using std::shared_ptr;
using std::make_shared;
using namespace std;


class CollisionReaction{

public:
			CollisionReaction();
			void updateBullets(list<shared_ptr<Bullet>>& bullets);
			void updateSegments(list<shared_ptr<Segment>>& segments);
};
#endif