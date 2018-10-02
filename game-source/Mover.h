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
		bool isAtMinXBound(float x)const;
		bool isAtMaxXBound(float x)const;
		bool isAtMinYBound(float y)const;
		bool isAtMaxYBound(float y)const;
//		bool minXBound(int x_coord);
//		bool maxXBound(int x_coord);
//		bool maxYBound(int y_coord);
private:
        unique_ptr<Position> position_;
        float speed_;
        float getSpeed()const;
//		bool minXBound(int x_coord);
//		bool maxXBound(int x_coord);
//		bool maxYBound(int y_coord);
};

#endif 