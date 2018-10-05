#ifndef FIELD_H
#define FIELD_H


#include "Position.h"
#include "Mushroom.h"
#include "Constants.h"
#include "Mover.h"
#include "Entity.h"

#include <iostream>
#include <list>
using namespace std;

#include <memory>
using std::shared_ptr;
using std::make_shared;

using Mushrooms = list<shared_ptr<Mushroom>>;

class InvalidFieldSize{};

class Field{
	
public:
	Field(int numberOfMushrooms);
	Mushrooms& getMushrooms();
private:
	Mushrooms mushrooms_;
	list<float>xPositions_;
	list<float>yPositions_;
	void createMushrooms(int numberOfMushrooms);
	void generateXPositions(int numberOfMushrooms);
	void generateYPositions(int numberOfMushrooms);
};
#endif