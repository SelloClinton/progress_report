#ifndef UPDATE_H
#define UPDATE_H

#include "Player.h"
#include "Centipede.h"
#include "segment.h"
#include "CollisionDetection.h"
#include "CollisionReaction.h"
#include "Laser.h"
#include "GameEngine.h"
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
		void updatePlayer(shared_ptr<Player> player, Pressed key); //player movement and shooting
		void updateCentipede(shared_ptr<Centipede> centipede, shared_ptr<Field> field);//centipede movement
		void checkBulletSegmentCollision(list<shared_ptr<Segment>> segments, list<shared_ptr<Bullet>> bullets);
		void handleBulletSegmentCollision(list<shared_ptr<Segment>>& segments,list<shared_ptr<Bullet>>& bullets, list<shared_ptr<Mushroom>>& mushrooms);
		void checkBulletMushroomCollision(list<shared_ptr<Bullet>> bullets, list<shared_ptr<Mushroom>> mushrooms);
		void handleBulletMushroomsCollision(list<shared_ptr<Bullet>>& bullets, list<shared_ptr<Mushroom>>& mushrooms);
		void checkSegmentPlayerCollision(list<shared_ptr<Segment>> segments, shared_ptr<Player> player);
		void checkSegmentMushroomCollision(shared_ptr<Centipede> centipede, list<shared_ptr<Mushroom>> mushrooms);

};
#endif