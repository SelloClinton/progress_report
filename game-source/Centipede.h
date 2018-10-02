#ifndef CENTIPEDE_H
#define CENTIPEDE_H

#include "Entity.h"
#include "Segment.h"
#include "Mover.h"
#include "Position.h"
#include "Constants.h"
#include "CollisionDetection.h"
#include "mushroom.h"

#include <tuple>
#include <list>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

using Segments = list<shared_ptr<Segment>>;

class InsufficientCentipedeSize{};

class Centipede{
    
public:
        Centipede(int centipedeSize);
        void move();
        Segments& getCentipede(){return centipede_;}
        void handleMushroom(shared_ptr<Segment> segment, list<shared_ptr<Mushroom>> mushrooms);
private:
        Segments centipede_;
        int centipede_size_;
		void initializePosition();
		void moveDown(shared_ptr<Segment>segment);
		void moveUp(shared_ptr<Segment> segment);
		void turnRight(shared_ptr<Segment>segment);
		void turnLeft(shared_ptr<Segment>segment);
		void keepUp(shared_ptr<Segment> segment);
		void keepDown(shared_ptr<Segment> segment);
        
};

#endif

