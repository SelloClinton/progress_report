#ifndef SEGMENT_H
#define SEGMENT_H

#include "Mover.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;



class Segment{
    
public:
		Segment(shared_ptr<Mover> attribute);
        shared_ptr<Mover> attribute();
        void faceLeft();
        void faceRight();
		void faceDown();
		void faceUp();
        bool isFacingLeft();
        bool isFacingRight();
		bool isFacingDown();
		bool isFacingUp();
private:
        shared_ptr<Mover> attribute_;
        bool right_flag_;
        bool left_flag_;
		bool down_flag_;
		bool up_flag_;
};

#endif 