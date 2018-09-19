#ifndef MOVER_H
#define MOVER_H

#include "Position.h"
#include "Enums.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <cassert> 

class NegativeZeroSpeed{};
    
class Mover{
    
public:
        Mover(shared_ptr<Position> _position, int speed);
        void move(Direction direction);
        shared_ptr<Position> position();
		bool isLive();
		void setLive();
		void destroy();
		bool minXBound(int x_coord);
		bool maxXBound(int x_coord);
private:
        shared_ptr<Position> position_;
        int speed_;
		bool live_;
        void setPosition(int x, int y);
        int getSpeed();
//		bool minXBound(int x_coord);
//		bool maxXBound(int x_coord);
		bool maxYBound(int y_coord);
};

#endif 