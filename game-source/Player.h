#ifndef PLAYER_H
#define PLAYER_H

#include "Mover.h"
#include "Position.h"
#include "Bullet.h"

#include <tuple>
#include <vector>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

using Bullets = vector<shared_ptr<Bullet>>;

class Player{
	
public:
		Player(shared_ptr<Mover> attribute);
        shared_ptr<Mover>attribute();
		void shoot();
		void updateBullet();
		Bullets getBullets(){return bullets_;}
private:
        shared_ptr<Mover> attribute_;
		Bullets bullets_;
};
#endif // PLAYER_H
