#ifndef PLAYER_H
#define PLAYER_H
#include "Mover.h"
#include "Position.h"
#include "Bullet.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Player{
	
public:
		Player(shared_ptr<Mover> attribute);
        shared_ptr<Mover> getAttribute();
		void shoot();
		shared_ptr<Bullet> getBullet(){return bullet_;}
private:
        shared_ptr<Mover> attribute_;
		shared_ptr<Bullet> bullet_;
		void updateBullet();
};
#endif // PLAYER_H