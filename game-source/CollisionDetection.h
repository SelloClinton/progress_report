#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "Box.h"
#include "Position.h"
#include "Entity.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;

class ObjectsNotCollidable{};

class CollisionDetection{
public:
        CollisionDetection(float x_position_A,float y_position_A,const EntityID& objectA,
						   float x_position_B, float y_position_B, const EntityID& objectB);	
        bool collided();
private:
	float x_position_A_;
	float y_position_A_;
    EntityID object_A_;
	float x_position_B_;
	float y_position_B_;
    EntityID object_B_;

    float min_x_A_;
    float min_y_A_;
	float max_x_A_;
	float max_y_A_;
    float min_x_B_;
    float min_y_B_;
	float max_x_B_;
	float max_y_B_;
    
    void createBoxes();
	bool isCollidable(const EntityID& objectA, const EntityID& objectB);
    
};
#endif