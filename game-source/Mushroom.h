#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Position.h"
#include <cstdlib>
#include <ctime>
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Mushroom{

public:	
		Mushroom(shared_ptr<Position>position);
		shared_ptr<Position>position();
		bool isLive()const;
		void weaken();
private:
		shared_ptr<Position>position_;
		int number_of_lives;
		bool live_;
};
#endif