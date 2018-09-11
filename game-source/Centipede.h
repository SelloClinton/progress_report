#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include <iostream>

#include "Segment.h"
#include "Mover.h"
#include "Position.h"
#include "Constants.h"

#include <tuple>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

using Segments = vector<shared_ptr<Segment>>;

class InsufficientCentipedeSize{};

class Centipede{
    
public:
        Centipede(int centipedeSize);
        void moveSegments();
        Segments getCentipede(){return centipede_;}
private:
        Segments centipede_;
        int centipede_size_;
		void initializePosition();
		void moveDown(shared_ptr<Segment>segment);
        
};

#endif

