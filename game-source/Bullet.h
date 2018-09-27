#ifndef BULLET_H
#define BULLET_H

#include "Mover.h"
#include "Constants.h"
#include "Enums.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;



class Bullet{
	
public:
		Bullet(shared_ptr<Mover> attribute);
		shared_ptr<Mover> attribute();
        void moveUp();
private:
		shared_ptr<Mover> attribute_;
};

#endif