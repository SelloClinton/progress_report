#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "Box.h"
#include "Position.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;

class CollisionDetection{
public:
        CollisionDetection(int x_position_A,int y_position_A,Object objectA, int x_position_B, int y_position_B, Object objectB);	//shared_ptr<Position>position_A, Object objectA, shared_ptr<Position>position_B, Object objectB);
        bool collided();
private:
	int x_position_A_;
	int y_position_A_;
    Object object_A_;
	int x_position_B_;
	int y_position_B_;
    Object object_B_;

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