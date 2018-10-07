#ifndef UPDATE_H
#define UPDATE_H

#include "Player.h"
#include "Centipede.h"
#include "segment.h"
#include "CollisionDetection.h"
#include "CollisionReaction.h"
#include "Laser.h"
#include "Field.h"
#include "Enums.h"
#include "Mushroom.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <list>
using std::list;
#include <iostream>


class Update{
	
	public:
		Update();
		void updateGame(shared_ptr<Player>player,Pressed key,shared_ptr<Centipede> centipede,shared_ptr<Field> field);
	private:
		shared_ptr<CollisionReaction> collision_reactor_;
		void updatePlayer(shared_ptr<Player> player, Pressed key);
		void updateCentipede(shared_ptr<Centipede> centipede, shared_ptr<Field> field);
		void checkLaserSegmentCollision(list<shared_ptr<Segment>>& segments, list<shared_ptr<Laser>>& lasers);
		void handleLaserSegmentCollision(list<shared_ptr<Segment>>& segments,list<shared_ptr<Laser>>& lasers,shared_ptr<Field> field);
		void checkLaserMushroomCollision(list<shared_ptr<Laser>>& lasers, list<shared_ptr<Mushroom>>& mushrooms);
		void handleLaserMushroomsCollision(list<shared_ptr<Laser>>& laser, list<shared_ptr<Mushroom>>& mushrooms);
		void checkSegmentPlayerCollision(list<shared_ptr<Segment>>& segments, shared_ptr<Player> player);
		void checkSegmentMushroomCollision(shared_ptr<Centipede> centipede, list<shared_ptr<Mushroom>>& mushrooms);

};
#endif