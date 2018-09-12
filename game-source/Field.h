#ifndef FIELD_H
#define FIELD_H

#include "Mushroom.h"
#include "Constants.h"
#include "Position.h"

#include <list>
using std::list;

#include <memory>
using std::shared_ptr;
using std::make_shared;

using Mushrooms = list<shared_ptr<Mushroom>>;
using Positions = list<shared_ptr<Position>>;


class Field{
	
public:
	Field(int numberOfMushrooms);
	Mushrooms& getMushrooms();
private:
	Mushrooms mushrooms_;
	Positions positions_;
	list<int>xPositions_;
	list<int>yPositions_;
	void createMushrooms(int numberOfMushrooms);
	void generateXPositions(int numberOfMushrooms);
	void generateYPositions(int numberOfMushrooms);
	void createPositions();
	
		
};
#endif