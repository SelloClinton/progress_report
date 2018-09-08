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
//        int size()const{centipede_size_;}
        Segments getCentipede(){return centipede_;}
private:
        Segments centipede_;
//		void createCentipede(shared_ptr<Mover>);
		void initializePosition();
        int centipede_size_;
        void faceRight(shared_ptr<Segment>segment);
        void faceLeft(shared_ptr<Segment>segment);
        bool leftFlag_;
        bool rightFlag_;
        bool isFacingLeft(shared_ptr<Segment>segment,int x_position);
        bool isFacingRight(shared_ptr<Segment>segment, int x_position);
        
};

#endif

