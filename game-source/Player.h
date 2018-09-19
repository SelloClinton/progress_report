#ifndef PLAYER_H
#define PLAYER_H

#include "Mover.h"
#include "Position.h"
#include "Bullet.h"
#include "Constants.h"
#include "Enums.h"

#include <tuple>
using std::tuple;
#include <list>
#include <iostream>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

using Bullets = list<shared_ptr<Bullet>>;

class Player{
	
public:
		Player(shared_ptr<Mover> attribute);
        shared_ptr<Mover>attribute();
		void moveUp();
		void moveDown();
		void shoot();
		void updateBullet();
		Bullets& getBullets(){return bullets_;}
private:
        shared_ptr<Mover> attribute_;
		Bullets bullets_;
};
#endif // PLAYER_H
