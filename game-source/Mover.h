#ifndef MOVER_H
#define MOVER_H

#include "Position.h"
#include "Constants.h"
//#include "Enums.h"

#include <iostream>

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
#include <tuple>
using std::tuple;
 

class NegativeZeroSpeed{};

    
class Mover{
    
public:
        Mover(float x_position, float y_position,float speed);
		tuple<float,float>position();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

private:
        shared_ptr<Position> position_;
        float speed_;
        float getSpeed()const;
		bool isAtMinXBound(float x)const;
		bool isAtMaxXBound(float x)const;
		bool isAtMinYBound(float y)const;
		bool isAtMaxYBound(float y)const;
};

#endif 