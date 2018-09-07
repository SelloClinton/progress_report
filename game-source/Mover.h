#ifndef MOVER_H
#define MOVER_H

#include "Position.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <cassert> 

class NegativeZeroSpeed{};

enum class Direction{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
    
class Mover{
    
public:
        Mover(shared_ptr<Position> _position, int speed);
        void move(Direction direction);
        shared_ptr<Position> position();
        
private:
        shared_ptr<Position> position_;
        int speed_;
        void setPosition(int x, int y);
        int getSpeed();
};

#endif 