#ifndef MOVER_H
#define MOVER_H
#include "Position.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;


//#include "Movement.h"

enum class Direction{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
    
class Mover{
    
public:
        Mover(Position position);
        void move(Direction direction);
        Position& getPosition();
        
private:
        Position position_;
        int speed_;
        void setPosition(int x, int y);
        int getSpeed();
};

#endif 