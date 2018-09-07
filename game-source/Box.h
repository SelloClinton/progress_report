#ifndef BOX_H
#define BOX_H
#include <tuple>
#include "Position.h"
#include "Constants.h"
#include <cassert>
using std::get;

enum class Object{
		PLAYER,
		BULLET,
		SEGMENT
};

class Box{
public:
		Box(Position position);
		tuple<int,int,int,int>getBox(Object object);
private:
		Position position_;
		tuple<int,int,int,int>createBox(Object object);

};
#endif