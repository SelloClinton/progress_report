#ifndef BOX_H
#define BOX_H
//
#include <memory>
#include <tuple>
#include "Position.h"
#include "Constants.h"
#include <cassert>
using std::get;
using std::shared_ptr;
using std::make_shared;


enum class Object{
		PLAYER,
		BULLET,
		SEGMENT
};

class Box{
public:
		Box();
		tuple<int,int,int,int>getBox(int x,int y, Object object);
private:
		tuple<int,int,int,int>createBox(int x, int y, Object object);

};
#endif