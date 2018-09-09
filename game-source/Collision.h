#ifndef COLLOSION_H
#define COLLOSION_H

#include "Box.h"
#include "Position.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;

class Collision{
public:
        Collision(shared_ptr<Position>position_A, Object objectA, shared_ptr<Position>position_A, Object objectB);
        bool collided();
private:
    shared_ptr<Position> object_position_A_;
    shared_ptr<Position> object_position_B_;
    Object object_A_;
    Object object_B_;
    shared_ptr<Box>box_A;
    shared_ptr<Box>box_B;
    int min_x_A_;
    int min_y_A_;
    int max_x_B_;
    int max_y_B_;
    
    void createBoxes();
    
};
#endif