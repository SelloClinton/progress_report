#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include "Segment.h"
#include "Mover.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

using Segments = vector<shared_ptr<Segment>>;

class Centipede{
    
public:
        Centipede(shared_ptr<Mover> attribute);
        void moveSegments();
        Segments getCentipede(){return centipede_;}
    
private:
        Segments centipede_;
		
		void createCentipede(shared_ptr<Mover>);
    
};

#endif

