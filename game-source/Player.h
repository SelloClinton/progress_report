#ifndef PLAYER_H
#define PLAYER_H

#include "Mover.h"
#include "Position.h"
#include "Bullet.h"

#include <tuple>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Player{
	
public:
		Player(shared_ptr<Mover> attribute);
        shared_ptr<Mover> attribute();
		void shoot();
		void updateBullet();
		shared_ptr<Bullet> getBullet(){return bullet_;}
private:
        shared_ptr<Mover> attribute_;
		shared_ptr<Bullet> bullet_;
//		void updateBullet();
};
#endif // PLAYER_H
