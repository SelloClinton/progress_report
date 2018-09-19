#ifndef BULLET_H
#define BULLET_H

#include "Mover.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;



class Bullet{
	
public:
		Bullet(shared_ptr<Mover> attribute);
		shared_ptr<Mover> attribute();
private:
		shared_ptr<Mover> attribute_;
};

#endif