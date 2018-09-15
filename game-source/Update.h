#ifndef UPDATE_H
#define UPDATE_H

#include "Player.h"
#include "Centipede.h"
#include "segment.h"
#include "CollisionDetection.h"
#include "CollisionReaction.h"
#include "Bullet.h"
#include "GameEngine.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

class Update{
	
	public:
		Update(shared_ptr<Player> player,shared_ptr<Centipede>centipede,shared_ptr<Field> field);
		void updateGame();
	private:
		shared_ptr<Player>player_;
		shared_ptr<Centipede> centipede_;
		shared_ptr<Field> field_;
			
		void updatePlayer();
		void updateCentipede(shared_ptr<Field> field);
		void checkBulletSegmentCollision(shared_ptr<Segment> segment, shared_ptr<Bullet> bullet);
		void handleBulletSegmentCollision(shared_ptr<Segment> segment,shared_ptr<Bullet> bullet);
		void checkSegmentPlayerCollision(shared_ptr<Segment> segment);
		void handleSegmentPlayerCollision(shared_ptr<Segment> segment);
};
#endif