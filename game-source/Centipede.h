#ifndef SEGMENT_H
#define SEGMENT_H

#include "Segment.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

using Segments = vector<Segment>;

class Centipede{
    
public:
        Centipede(shared_ptr<Mover> attribute);
        void moveSegments();
        Segments getCentipede(){return centipede_;}
    
private:
        Segments centipede_;
    
};

#endif