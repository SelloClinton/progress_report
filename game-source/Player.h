#ifndef PLAYER_H
#define PLAYER_H

#include "Mover.h"
#include "Position.h"
#include "Laser.h"
#include "Constants.h"
//#include "Enums.h"
#include "Entity.h"

#include <cassert>
#include <tuple>
using std::tuple;
using std::get;
#include <list>
#include <iostream>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

using Lasers = list<shared_ptr<Laser>>;

class IncorrectPlayerSpeed{};
class IncorrectPlayerEntityID{};
class IncorrectPlayerPosition{};

class Player{
	
public:
	Player(float x_position, float y_position, const EntityID& id, float speed);
	shared_ptr<Entity> entityAttribute();
	void move(Direction direction);
	void shoot();
	Lasers& getLasers();
	void updateLasers();
private:
	shared_ptr<Entity> entity_attribute_;
	Lasers lasers_;
};
#endif // PLAYER_H
