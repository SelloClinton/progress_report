#ifndef SEGMENT_H
#define SEGMENT_H

#include "Mover.h"
#include "Entity.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;
#include <cassert>

class InvalidSegmentSpeed{};
class InvalidSegmentEntityID{};

class Segment{
    
public:
		Segment(float x_position, float y_position,const EntityID& id, float speed);
        shared_ptr<Entity> entityAttribute();
		void move(Direction direction);
        void faceLeft();
        void faceRight();
		void faceDown();
		void faceUp();
        bool isFacingLeft();
        bool isFacingRight();
		bool isFacingDown();
		bool isFacingUp();
private:
        shared_ptr<Entity> entity_attribute_;
        bool right_flag_;
        bool left_flag_;
		bool down_flag_;
		bool up_flag_;
};

#endif 