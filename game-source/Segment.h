#ifndef SEGMENT_H
#define SEGMENT_H

#include "Mover.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;



class Segment{
    
public:
		Segment(shared_ptr<Mover> attribute);
        shared_ptr<Mover> getAttribute();
private:
        shared_ptr<Mover> attribute_;
};

#endif 