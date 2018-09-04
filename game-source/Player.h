#ifndef PLAYER_H
#define PLAYER_H
#include "Mover.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Player{
	
public:
		Player(shared_ptr<Mover> attribute);
        shared_ptr<Mover> getAttribute();
private:
        shared_ptr<Mover> attribute_;
};
#endif // PLAYER_H