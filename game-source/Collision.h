#ifndef COLLISION_H
#define COLLISION_H

#include "Box.h"
#include "Position.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;

class Collision{
public:
        Collision(int x_position_A,int y_position_A,Object objectA, int x_position_B, int y_position_B, Object objectB);	//shared_ptr<Position>position_A, Object objectA, shared_ptr<Position>position_B, Object objectB);
        bool collided();
private:
//    shared_ptr<Position> object_position_A_;
	int x_position_A_;
	int y_position_A_;
    Object object_A_;
	int x_position_B_;
	int y_position_B_;
    Object object_B_;
//    shared_ptr<Position> object_position_B_;

//    shared_ptr<Box>box_A;
//    shared_ptr<Box>box_B;
    int min_x_A_;
    int min_y_A_;
	int max_x_A_;
	int max_y_A_;
    int min_x_B_;
    int min_y_B_;
	int max_x_B_;
	int max_y_B_;
    
    void createBoxes();
    
};
#endif