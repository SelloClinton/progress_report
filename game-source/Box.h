#ifndef BOX_H
#define BOX_H

#include <memory>
#include <tuple>
#include "Position.h"
#include "Constants.h"
#include "Enums.h"
#include "Entity.h"
#include <cassert>
using std::get;
using std::shared_ptr;
using std::make_shared;


class Box{
public:
		Box();
		tuple<float,float,float,float>getBox(float x,float y, const EntityID& object);
private:
		tuple<float,float,float,float>createBox(float x, float y, const EntityID& object);

};
#endif
