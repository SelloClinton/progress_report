#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <iostream>

#include "Segment.h"
#include "Mover.h"
#include "Position.h"

#include <tuple>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

using Segments = vector<shared_ptr<Segment>>;

class Centipede{
    
public:
        Centipede(shared_ptr<Mover> _attribute);
        void moveSegments();
        Segments getCentipede(){return centipede_;}
    
private:
        Segments centipede_;
		void createCentipede(shared_ptr<Mover>);
//		void initialPosition();
		int number_of_segments;
};

#endif

